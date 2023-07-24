#pragma once

#include "main.h"

// Chat buffer size
#define CHAT_BUFFER_SIZE 131072

class ChatGPT
{
public:
	// Chat buffer, for storing request payload JSON
	char* chatbuf;

	// Prompt buffer
	char* promptbuf;

	// TCP handle
	int tcp_hdl;

	// Enable log or not
	bool enable_log;

	// Init
	void init();

	// Chat
	void chat(const char* msg);

	// TCP callback
	void tcp_callback(VMINT handle, VMINT event);

	// Receive response
	void receive();

	// Send
	void send_data(char* data);

	// Add
	void add(char c);

	// Delete
	void del();

	// Submit
	void submit();

	// Toggle log button
	void toggle_log();
};
