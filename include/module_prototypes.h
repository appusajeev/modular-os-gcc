#ifndef MODULE_PROTOTYPES_H
#define MODULE_PROTOTYPES_H

#include <common.h>

typedef UINT8 COLOR;


typedef enum ServiceId_{


	MODULE_GRAPHICS,
	MODULE_DEBUG,
	MODULE_FILE_SYSTEM,
	MODULE_MEMORY,
	MODULE_GENERIC

}ServiceId_t;


typedef struct{


	void (*FATAL)(char *);
	void (*INFO0)(char *);
	void (*INFO1)(char *);
	void (*INFO2)(char *);
	void (*SetVerbosity)(UINT8);


}DebugMessageHandler_t;

typedef struct 
{

	void (*Initialize)();
	void (*WriteText)(const char * Message);
	void (*ClearScreen)();
	void (*SetCurrentTextPosition)(UINT32 VerticalPixelPosition, UINT32 HorizontalPixelPosition);
	void (*SetTextBackgroundColor) (COLOR BackgroundColor);
	void (*SetScreenBackgroundColor) (COLOR BackgroundColor);
	void (*SetTextColor) (COLOR ForegroundColor);
	void (*CustomConfig)(UINT8 Param);
	void (*FillBox)(UINT32 StartPixelX, UINT32 StartPixelY, UINT32 LengthHorizontal, UINT32 BreadthVertical, COLOR FillColor);
	UINT32 MaxPixelsHorizontal;
	UINT32 MaxPixelsVertical;
	
}DisplayAdapter_t;



#endif
