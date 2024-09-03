#pragma once
class CircleBuf
{
	char *buf;
	int buf_size;
	int rpos, wpos;

	void inc_rpos();
	void inc_wpos();
public:

	void init(int size);
	char pop();
	char view();
	bool push(char c);
	int get_data_size();

	char pop_blok();
	char view_blok();
};

