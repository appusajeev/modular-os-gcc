#include <common.h>
//#include <display_adapter.h>
#include <legacy_vga_adapter.h>
#define VGA_COLOR_BYTE(BACKGROUND, FOREGROUND)  ((BACKGROUND << 4) | FOREGROUND)


VgaDescriptor_t VgaAdapter = {(UINT8 *)VGAVIDEOMEM_BASE, 0, 0, /* Background Color */COLOR_BLACK, /* Text Color */COLOR_WHITE};
void VgaWriteCharacter(UINT8 Character)
{


	UINT8 CurrentX = VgaAdapter.CurrentXPosition;
	UINT8 CurrentY = VgaAdapter.CurrentYPosition;

	WriteByte(VgaAdapter.VgaBase, VGA_GET_ADDRESS(CurrentX, CurrentY), Character); 	
	//WriteByte(VgaAdapter.VgaBase, VGA_GET_ADDRESS(CurrentX, CurrentY) + 1, (VgaAdapter.CurrentBackgroundColor << 4)|VgaAdapter.CurrentForegroundColor ); 	
	WriteByte(VgaAdapter.VgaBase, VGA_GET_ADDRESS(CurrentX, CurrentY) + 1, VGA_COLOR_BYTE(VgaAdapter.CurrentBackgroundColor, VgaAdapter.CurrentForegroundColor)); 	

	VgaAdapter.CurrentYPosition = ((CurrentY + 1 ) == (VGA_MAX_Y - 1) )? 0: CurrentY + 1;
	VgaAdapter.CurrentXPosition =  (VgaAdapter.CurrentYPosition == 0) ? CurrentX + 1: CurrentX;

}

void VgaWriteText(const char * Message)
{
	while (*Message) VgaWriteCharacter(*Message++);

}


void VgaInit()
{

/* ---- TODO-------

MARK THE VIDEO REGION AS WC TO AVOID Cache Pollution


*/




}

void VgaClearScreen()
{

	UINT16 Pattern = VGA_COLOR_BYTE(VgaAdapter.CurrentBackgroundColor,  VgaAdapter.CurrentForegroundColor)  ;
	//UINT16 Pattern = VGA_COLOR_BYTE(0,  0)  ;
	//Pattern = 0x61 | (0xf)<<8  ;
	MemoryFillPattern(VgaAdapter.VgaBase, VGA_MAX_Y * VGA_MAX_X * 2 , (Pattern & 0xff) << 8   ,  2);
	


}


void VgaReDraw()
{
	UINT32 Offset;
	for (Offset = 1; Offset < VGA_MAX_X * VGA_MAX_Y * 2 ; Offset += 2){
		*((UINT8 *)VgaAdapter.VgaBase + Offset ) = VGA_COLOR_BYTE(VgaAdapter.CurrentBackgroundColor,  VgaAdapter.CurrentForegroundColor)  ;
	}	

}

void VgaGotoXY(UINT32 x, UINT32 y)
{

	VgaAdapter.CurrentXPosition = x;
	VgaAdapter.CurrentYPosition = y;


}

void VgaSetTextBackgroundColor(COLOR BackgroundColor){

	VgaAdapter.CurrentBackgroundColor = BackgroundColor;


}

void VgaSetScreenBackgroundColor(COLOR BackgroundColor){

	VgaSetTextBackgroundColor(BackgroundColor);
	VgaReDraw();

}
void VgaSetForegroundColor(COLOR ForegroundColor){

	VgaAdapter.CurrentForegroundColor = ForegroundColor;

}




void VgaCustomCommand(UINT8 Command){



}


void VgaFillBox(UINT32 StartX, UINT32 StartY, UINT32 Length, UINT32 Breadth, COLOR FillColor)
{


}

DisplayAdapter_t LegacyVgaAdapter= {	VgaInit,
					VgaWriteText,
				   	VgaClearScreen,
					VgaGotoXY,
				   	VgaSetTextBackgroundColor,
				   	VgaSetScreenBackgroundColor,
				   	VgaSetForegroundColor,
				   	VgaCustomCommand,
				   	VgaFillBox,
				   	VGA_MAX_Y,
				   	VGA_MAX_X
				   
				};



