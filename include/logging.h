#ifndef LOGGING_H
#define LOGGING_H


#include <common.h>

void FATAL(char * Message);
void INFO0(char * Message);
void INFO1(char * Message);
void INFO2(char * Message);
void SetLogVerbosity(UINT8 Verbosity);


#endif
