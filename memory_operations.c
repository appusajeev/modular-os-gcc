#include <common.h>


void MemoryCopy(UINT8 * Source, UINT8 * Destination, UINT32 NumberOfBytes){

	UINT32 BytesCopied = 0;
	while (BytesCopied < NumberOfBytes){
		*Destination++ = *Source++;
		 BytesCopied++;
	}

	asm volatile("cld\n"
		     "rep movsb"
		     ::"D"(Destination), "S"(Source), "c"(NumberOfBytes));	
}


void MemoryFillPattern(UINT8 * Address,UINT32 NumberOfBlocks, UINT32 Pattern, UINT8 PatternSize){

	UINT32 BytesWritten = 0;

	UINT32 NumberOfBytes = NumberOfBlocks;
	if (PatternSize == 1)
	{
		while (BytesWritten < NumberOfBytes)
		{
			*Address++ = Pattern;
			BytesWritten++;
		}

	}
	else if (PatternSize == 2)
	{

		while(BytesWritten < NumberOfBytes){

		//*(UINT16 *)Address++ = Pattern;
		*(UINT16 *)Address = Pattern & 0xFFFF;
		Address+=2;
		BytesWritten+=1;

		}

	}

	
	asm volatile("cld\n"
		     "rep stosb"
		     ::"a"(Pattern), "D"(Address), "c"(NumberOfBytes));

}

void WriteByte(UINT8 * Address, UINT64 Offset, UINT8 Value){

	*(Address + Offset) = Value & 0xFF;
}
