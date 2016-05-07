

#include <common.h>
#include <modules.h>
#include <display_adapter.h>



void InstallModule(ServiceId_t ServiceId, void * ModuleDescriptor){



	switch (ServiceId)
	{

		case MODULE_GRAPHICS:
		GraphicsSetCurrentDisplayAdapter((DisplayAdapter_t *)ModuleDescriptor);
		break;

		case MODULE_DEBUG:
		break;

		case MODULE_FILE_SYSTEM:
		break;

		case MODULE_MEMORY:
		break;

	
	
		case MODULE_GENERIC:
		break;



	}



}
