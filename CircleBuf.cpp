#include "CircleBuf.h"
#include "vmsys.h"
#include "thread.h"

void CircleBuf::init(int size){
	rpos = wpos = 0;
	buf_size = size;
	buf = (char*)vm_malloc(size); // posibly memory leak
}

char CircleBuf::pop(){
	if(get_data_size()){
		char res = buf[rpos];
		inc_rpos();
		return res;
	}
	return 0;
}

char CircleBuf::view(){
	if(get_data_size())
		return buf[rpos];
	return 0;
}

bool CircleBuf::push(char c){
	if(rpos<=wpos || wpos+1<rpos){
		buf[wpos] = c;
		inc_wpos();
	}
	return false;
}

int CircleBuf::get_data_size(){
	if(rpos <= wpos)
		return wpos - rpos;
	else
		return wpos + buf_size - rpos;
}

char CircleBuf::pop_blok(){
	while(!get_data_size()) thread_next();

	char res = buf[rpos];
	inc_rpos();
	return res;
}

char CircleBuf::view_blok(){
	while(!get_data_size()) thread_next();

	return buf[rpos];
}

void CircleBuf::inc_rpos(){
	if(++rpos >= buf_size)
		rpos = 0;
}

void CircleBuf::inc_wpos(){
	if(++wpos >= buf_size)
		wpos = 0;
}