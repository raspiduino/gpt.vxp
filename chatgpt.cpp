#include "Console.h"
#include "chatgpt.h"
#include "vmsock.h"
#include "Console_io.h"

// Free ChatGPT endpoint. You can use any endpoint you want
const char* host = "free.churchless.tech";

// Port to connect. We don't have HTTPS support is complicated, so we use HTTP instead.
// In the future you might want to implement HTTPS
const VMINT port = 80;

// API path
const char* path = "/v1/chat/completions";

// API key
// Join this endpoint's author's discord at https://discord.gg/CH8DBabS
const char* key = "MyDiscord";

extern ChatGPT chatgpt;
char* pl;

static void _tcp_callback(VMINT handle, VMINT event) {
	chatgpt.tcp_callback(handle, event);
}

void ChatGPT::init() {
	// Allocate buffers
	chatbuf = (char*)vm_calloc(CHAT_BUFFER_SIZE);
	promptbuf = (char*)vm_calloc(1024);

	// Init payload
	sprintf(chatbuf, "{\"model\":\"gpt-3.5-turbo\",\"temperature\":1,\"presence_penalty\":0,\"top_p\":1,\"frequency_penalty\":0,\"messages\":[{\"role\":\"system\",\"content\":\"You are ChatGPT, a large language model trained by OpenAI.\\nCarefully heed the user\'s instructions. \\nRespond using Markdown. Due to endpoint device limitation, your response must be broken down to 410 characters parts, or the rest of your response won't be displayed.\"}]}");

	// TCP handle
	tcp_hdl = -1;

	// Disable log by default
	enable_log = false;

	// Current prompt
	current_prompt = 0;

	// Number of prompts
	n_prompt = 0;
}

void ChatGPT::add(char c) {
	int s = strlen(promptbuf);

	// TODO: Add character escape here before adding to buffer
	promptbuf[s] = c;
	console_char_in(c);
}

void ChatGPT::add_string(const char* s) {
	for (int i = 0; i < strlen(s); i++) {
		add(s[i]);
	}
}

void ChatGPT::del() {
	if (strlen(promptbuf) == 0) return;
	promptbuf[strlen(promptbuf) - 1] = '\0';
	console_char_in('\b\b'); // Sending \b\b for deleting character on the screen
}

void ChatGPT::submit() {
	console_str_in("\n");
	chat(promptbuf);
	vm_free(promptbuf);
	promptbuf = (char*)vm_calloc(1024);
	current_prompt = ++n_prompt;
}

void ChatGPT::toggle_log() {
	enable_log = !enable_log;
}

void ChatGPT::chat(const char* msg) {
	// Add message to payload buffer
	// We overwrite the last 2 character in the chatbuf, which is ]}, to continue writting to the message array.
	sprintf(chatbuf + (strlen(chatbuf) - 2), ",{\"role\":\"user\",\"content\":\"%s\"}]}", msg);

	// Create full HTTP header payload
	pl = (char*)vm_calloc(strlen(chatbuf) + 256);
	sprintf(pl, "POST /v1/chat/completions HTTP/1.1\r\nHost: %s\r\nAccept: */*\r\nAuthorization: Bearer %s\r\nUser-Agent: Nokia\r\nContent-Type: application/json\r\nContent-Length: %d\r\n\r\n%s", host, key, strlen(chatbuf), chatbuf);

	// Establish TCP connection to endpoint
	tcp_hdl = vm_tcp_connect(host, port, 1, _tcp_callback);
	if (enable_log) {
		char tmp[50];
		sprintf(tmp, "tcp_hdl=%d\n", tcp_hdl);
		console_str_in(tmp);
	}
}

void ChatGPT::tcp_callback(VMINT handle, VMINT event) {
	if (handle != tcp_hdl)
		return;

	switch (event) {
	case VM_TCP_EVT_CONNECTED:
		if (enable_log) console_str_in("TCP connected\n");
		send_data(pl);
		vm_free(pl);
		break;
	case VM_TCP_EVT_CAN_WRITE:
		break;
	case VM_TCP_EVT_CAN_READ:
		receive();
		break;
	case VM_TCP_EVT_PIPE_BROKEN:
	case VM_TCP_EVT_HOST_NOT_FOUND:
	case VM_TCP_EVT_PIPE_CLOSED:
		vm_tcp_close(tcp_hdl);
		char tmp[50];
		sprintf(tmp, "\n\033[mConnect is close (code %d)\n", event);
		console_str_in(tmp);
		break;
	}
}

void ChatGPT::send_data(char* data) {
	// Calculate the data length, if not yet
	int len = strlen(data);
	int ll = len; // Length left to send

	// Send data until no data is left
	while (ll > 0) {
		int ss = vm_tcp_write(tcp_hdl, data + (len - ll), ll);
		if (ss <= 0) {
			// If ss <= 0 -> some error happened
			char tmp[50];
			sprintf(tmp, "\n\033[mError sending (code %d)\n", ss);
			console_str_in(tmp);
			return;
		}

		ll -= ss;
	}
}

char* strtokm(char* str, const char* delim)
{
	static char* tok;
	static char* next;
	char* m;

	if (delim == NULL) return NULL;

	tok = (str) ? str : next;
	if (tok == NULL) return NULL;

	m = strstr(tok, delim);

	if (m) {
		next = m + strlen(delim);
		*m = '\0';
	}
	else {
		next = NULL;
	}

	return tok;
}

void ChatGPT::receive() {
	if (enable_log) {
		console_str_in("Received result\n");
	}

	console_str_in("Bot: ");

	char* data = (char*)vm_calloc(20480);
	if (vm_tcp_read(tcp_hdl, data, 20480) > 0) {
		// We received something
		// Split the response
		char* s1 = strtokm(data, "\"content\":\"");
		s1 = strtokm(NULL, "\"content\":\"");
		char* msg = strtokm(s1, "\"},\"finish_reason\"");
		
		console_str_in(msg);

		// Add bot response to JSON string
		sprintf(chatbuf + (strlen(chatbuf) - 2), ",{\"role\":\"assistant\",\"content\":\"%s\"}]}", msg);
	}

	// Remember to free
	vm_free(data);
	
	console_str_in("\nUser: ");
	vm_tcp_close(tcp_hdl);
}

void ChatGPT::show_prompt() {
	// Clear current line and move cursor to the beginning
	console_str_in("\x1b[2K\x1b[G");

	// Copy the chatbuf
	char* b = (char*)vm_calloc(strlen(chatbuf) + 1);
	sprintf(b, "%s", chatbuf);

	// Get the pointed prompt
	char* s1 = strtokm(b, "\"role\":\"user\",\"content\":\"");

	// Free the copied chatbuf
	vm_free(b);

	for (int i = 0; i < current_prompt + 1; i++) {
		s1 = strtokm(NULL, "\"role\":\"user\",\"content\":\"");
	}

	char* s2 = strtokm(s1, "\"},{\"role\":\"assistant\"");
	
	// Show that prompt to the console
	console_str_in("User: ");
	console_str_in(s2);

	// Clear the promptbuf
	vm_free(promptbuf);
	promptbuf = (char*)vm_calloc(1024);

	// Fill new content
	sprintf(promptbuf, "%s", s2);
}

void ChatGPT::prev() {
	if (current_prompt <= 0) return;
	current_prompt--;

	show_prompt();
}

void ChatGPT::next() {
	if (current_prompt >= n_prompt) return;
	current_prompt++;

	show_prompt();
}
