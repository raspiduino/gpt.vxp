#include "Console_io.h"
#include "CircleBuf.h"
extern Console console;
extern T2Input t2input;
extern CircleBuf circlebuf;

void console_char_in(char ch){
	console.put_c(ch);
}

void console_str_in(const char* str){
	console.putstr(str);
}

void console_str_with_length_in(const char* str, int length){
	console.putstr(str, length);
}

void console_char_out(char ch){
	circlebuf.push(ch);
}

void console_str_out(const char* str){
	for(unsigned int i = 0; i < strlen(str); i++)
		console_char_out(str[i]);
}

void console_str_with_length_out(const char* str, int length){
	for(unsigned int i = 0; i < length; i++)
		console_char_out(str[i]);
}

int cprintf(const char* format, ...) {
	static char buf[1024 * 4];
	va_list aptr;

	va_start(aptr, format);
	int ret = vsprintf(buf, format, aptr);
	va_end(aptr);

	console_str_in(buf);
	return ret;
}