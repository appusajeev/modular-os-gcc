#include <common.h>
#include <vga_defines.h>

#define VIDEOMEM_BASE 0xA000


u16int *vidmem_addr = vidmem_base;
u16int *current = vidmem_base;

u8int color=0x24;
u8int bkcolor=0x3;
u8int forecolor = 0xf;
u8int c_x=0;
u8int c_y=0;


void ConsoleClear()
{
	

}

void ConsoleSetBackgroundColor(Color BackgroundColor)
{



}

void ConsoleWrite(char * Message)
{



}



void ConsoleGotoXY(UINT8 x, UINT8, y)
{



}
/*
void update_cursor()
{
	u16int loc  = (cols * c_y + c_x);
	outPort(0x3d4,14);
	outPort(0x3d5,loc>>8);
	outPort(0x3d4,15);
	outPort(0x3d5,loc);
}
*/
