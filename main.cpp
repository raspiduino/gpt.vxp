#include "main.h"
#include "Console.h"
#include "Console_io.h"
#include "CircleBuf.h"
#include "chatgpt.h"
#include "T2Input.h"
#include "vmtimer.h"
#include "thread.h"

//Global
int scr_w = 0, scr_h =0;
VMUINT8 *layer_bufs[2] = {0,0};
VMINT layer_hdls[2] = {-1,-1};

Console console;
T2Input t2input;
CircleBuf circlebuf;

int main_timer_id = -1;

void handle_sysevt(VMINT message, VMINT param);
void handle_keyevt(VMINT event, VMINT keycode);
void handle_penevt(VMINT event, VMINT x, VMINT y);


void vm_main(void){
	thread_init();
	thread_create(0xFFFF, main_gpt);

	scr_w = vm_graphic_get_screen_width(); 
	scr_h = vm_graphic_get_screen_height();

	console.init();
	t2input.init();
	circlebuf.init(1024);

	vm_reg_sysevt_callback(handle_sysevt);
	vm_reg_keyboard_callback(handle_keyevt);
	vm_reg_pen_callback(handle_penevt);
}

void draw(){
	vm_graphic_fill_rect(layer_bufs[1], 0, 0, scr_w, scr_h, tr_color, tr_color);
	vm_graphic_line(layer_bufs[1], console.cursor_x*char_width, (console.cursor_y+1)*char_height,
		(console.cursor_x+1)*char_width, (console.cursor_y+1)*char_height, console.cur_textcolor);
	t2input.draw();
	vm_graphic_flush_layer(layer_hdls, 2);
} 

void timer(int tid){
	thread_next();
	draw();
}

void handle_sysevt(VMINT message, VMINT param) {
	switch (message) {
	case VM_MSG_CREATE:
	case VM_MSG_ACTIVE:
		layer_hdls[0] = vm_graphic_create_layer(0, 0, scr_w, scr_h, -1);
		layer_hdls[1] = vm_graphic_create_layer(0, 0, scr_w, scr_h, tr_color);
		
		vm_graphic_set_clip(0, 0, scr_w, scr_h);

		layer_bufs[0]=vm_graphic_get_layer_buffer(layer_hdls[0]);
		layer_bufs[1]=vm_graphic_get_layer_buffer(layer_hdls[1]);

		vm_switch_power_saving_mode(turn_off_mode);

		console.scr_buf=layer_bufs[0];
		console.draw_all();

		t2input.scr_buf=layer_bufs[1];
		t2input.layer_handle=layer_hdls[1];

		if(main_timer_id==-1)
			main_timer_id = vm_create_timer(1000/15, timer); //15 fps
		break;
		
	case VM_MSG_PAINT:
		draw();
		break;
		
	case VM_MSG_INACTIVE:
		vm_switch_power_saving_mode(turn_on_mode);
		if( layer_hdls[0] != -1 ){
			vm_graphic_delete_layer(layer_hdls[0]);
			vm_graphic_delete_layer(layer_hdls[1]);
		}
		if(main_timer_id!=-1)
			vm_delete_timer(main_timer_id);
		break;	
	case VM_MSG_QUIT:
		if( layer_hdls[0] != -1 ){
			vm_graphic_delete_layer(layer_hdls[0]);
			vm_graphic_delete_layer(layer_hdls[1]);
		}
		if(main_timer_id!=-1)
			vm_delete_timer(main_timer_id);
		break;	
	}
}

void handle_keyevt(VMINT event, VMINT keycode) {
#ifdef WIN32
	if(keycode>=VM_KEY_NUM1&&keycode<=VM_KEY_NUM3)
		keycode+=6;
	else if(keycode>=VM_KEY_NUM7&&keycode<=VM_KEY_NUM9)
		keycode-=6;
#endif
	t2input.handle_keyevt(event, keycode);
	draw();
}

void handle_penevt(VMINT event, VMINT x, VMINT y){
	t2input.handle_penevt(event, x, y);
	draw();
}