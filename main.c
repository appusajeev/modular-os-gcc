
#include <gdt.h>
#include <idt.h>
#include <common.h>
#include <legacy_vga_adapter.h>
#include <modules.h>

extern DisplayAdapter_t LegacyVgaAdapter;

extern DisplayAdapter_t  *CurrentDisplayAdapter;

int main(struct multiboot *mboot_ptr)
{

	InstallModule(MODULE_GRAPHICS, (void *)&LegacyVgaAdapter);

	CurrentDisplayAdapter->ClearScreen();

	CurrentDisplayAdapter->SetTextBackgroundColor(COLOR_BLACK);
	CurrentDisplayAdapter->SetTextColor(COLOR_GREEN_LIGHT);

	CurrentDisplayAdapter->WriteText("Hello ! Welcome to Appu Sajeev OS! 2016");
	while(1);















}
