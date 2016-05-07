//#include <display_adapter.h>
#include <module_prototypes.h>
#include <common.h>

DisplayAdapter_t * CurrentDisplayAdapter;


void GraphicsSetCurrentDisplayAdapter(DisplayAdapter_t * Adapter){

	CurrentDisplayAdapter = Adapter;
	if (CurrentDisplayAdapter->Initialize) CurrentDisplayAdapter->Initialize(); 

}
