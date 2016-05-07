#include <common.h>

UINT8 LogCurrentVerbosity = 1;

void SetLogVerbosity (UINT8 Verbosity)
{

	LogCurrentVerbosity = Verbosity;
}

void FATAL (char * Message)
{


}




void INFO0 (char * Message)
{





}


void INFO01(char * Message)
{
	if (LogCurrentVerbosity >= 1)	
		INFO0(Message);

}

void INFO2(char * Message)
{

	if (LogCurrentVerbosity >= 2 )
		INFO0(Message);


}

