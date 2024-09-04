#define inline  
#include "bearssl.h"
#include "certificates.h"
#include "vmsys.h"
#include "vmsock.h"
#include "vmstdlib.h"
#include "Console_io.h"
#include "thread.h"

bool connected = false;
bool network_err = false;

int sock_read(void* ctx, unsigned char* buf, size_t len){
	for (;;) {
		int rlen;

		rlen = vm_tcp_read(*(int*)ctx, buf, len);
		if (rlen <= 0) {
			if (!network_err) {
				thread_next();
				continue;
			}
			return -1;
		}
		return (int)rlen;
	}
}

int sock_write(void* ctx, const unsigned char* buf, size_t len){
	for (;;) {
		int wlen;

		wlen = vm_tcp_write(*(int*)ctx, (void*)buf, len);
		if (wlen <= 0) {
			if (!network_err) {
				thread_next();
				continue;
			}
			return -1;
		}
		return (int)wlen;
	}
}

void tcp_callback(VMINT handle, VMINT event) {
	switch (event) {
	case VM_TCP_EVT_CONNECTED:
		connected = true;
		break;
	case VM_TCP_EVT_PIPE_BROKEN:
	case VM_TCP_EVT_HOST_NOT_FOUND:
	case VM_TCP_EVT_PIPE_CLOSED:
		network_err = true;
		break;
	}
}

br_ssl_client_context sc;
br_x509_minimal_context xc;
unsigned char iobuf[BR_SSL_BUFSIZE_BIDI];

void skip_to(br_sslio_context &ioc, const char* find_str){
	int len = strlen(find_str);
	int coincidence = 0;

	while(true){
		char c;
		int rlen = br_sslio_read(&ioc, &c, 1);
		if (rlen < 0) {
			break; //err
		}
		if(c == find_str[coincidence]){
			++coincidence;
			if(coincidence == 4)
				break;
		}else
			coincidence = 0;
	}

}

void https_request(const char* host, const char* path, const char* body, char* rbody, int &rbody_size){
	connected = true;
	network_err = false;

	int tcp_handle = vm_tcp_connect(host, 443, 1, tcp_callback);

	cprintf("0%%");

	while (!connected) thread_next();

	cprintf("\b\b25%%");

	br_ssl_client_init_full(&sc, &xc, TAs, TAs_NUM);
	br_ssl_engine_set_buffer(&sc.eng, iobuf, sizeof iobuf, 1);
	br_ssl_client_reset(&sc, host, 0);

	br_sslio_context ioc;
	br_sslio_init(&ioc, &sc.eng, sock_read, &tcp_handle, sock_write, &tcp_handle);

	{
		char head_tmp[512];
		sprintf(
			head_tmp,
			"POST %s HTTP/1.0\r\n"\
			"Host: %s\r\n"\
			"Content-Type: application/json\r\n"\
			"Content-Length: %d\r\n"\
			"\r\n",
			path,
			host,
			strlen(body)
		);
		br_sslio_write_all(&ioc, head_tmp, strlen(head_tmp));
	}
	br_sslio_write_all(&ioc, body, strlen(body));

	br_sslio_flush(&ioc);
	
	cprintf("\b\b\b50%%");

	skip_to(ioc, "\r\n\r\n"); // skip header

	cprintf("\b\b\b75%%");

	int readed = 0;

	for (;;) {
		if(readed == rbody_size)
			break;
		int rlen = br_sslio_read(&ioc, rbody + readed, rbody_size - readed);
		if (rlen < 0) 
			break;

		readed += rlen;
	}

	rbody_size = readed;

	vm_tcp_close(tcp_handle);

	if (br_ssl_engine_current_state(&sc.eng) == BR_SSL_CLOSED) {
		int err;

		err = br_ssl_engine_last_error(&sc.eng);
		if (err == 0) {
			//cprintf("closed.\n");
		}
		else {
			cprintf("SSL error %d\n", err);
		}
	}
	else {
		cprintf("socket closed without proper SSL termination\n");
	}

	cprintf("\b\b\b   \b\b\b");
}