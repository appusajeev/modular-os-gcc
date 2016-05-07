#ifndef LEGACY_VGA_ADAPTER_H
#define LEGACY_VGA_ADAPTER_H

#include <common.h>
#include <display_adapter.h>

#define VGAVIDEOMEM_BASE 0xB8000
#define VGA_MAX_X  25
#define VGA_MAX_Y  80

#define VGA_GET_ADDRESS(X, Y) ( X * VGA_MAX_Y + Y) * 2


typedef enum VgaColors{
	COLOR_BLACK,
	COLOR_BLUE_DARK,
	COLOR_GREEN_DARK,
	COLOR_CYAN_DARK,
	COLOR_RED_DARK,
	COLOR_MAGENTA_DARK,
	COLOR_BROWN_DARK,
	COLOR_GRAY_LIGHT,
	COLOR_GRAY_DARK,
	COLOR_BLUE_LIGHT,
	COLOR_GREEN_LIGHT,
	COLOR_CYAN_LIGHT,
	COLOR_RED_LIGHT,
	COLOR_MAGENTA_LIGHT,
	COLOR_YELLOW,
	COLOR_WHITE
} Color;



typedef struct {

	UINT8 * VgaBase;
	UINT8 CurrentXPosition;
	UINT8 CurrentYPosition;
	Color CurrentBackgroundColor;
	Color CurrentForegroundColor;

}VgaDescriptor_t;





#endif
