[global gdt_setup]
[global idt_setup]
[global tss_setup]
[global outPort]
[global inPort]

gdt_setup:
	mov eax, [esp + 4]
	lgdt [eax]
	mov ax,16
	mov ds, ax
	mov es, ax
	;mov ax, 5<<3
	mov ss, ax
	mov fs, ax
	mov gs, ax
	jmp 8:foo
foo:
	ret

idt_setup:
	mov eax, [esp + 4]
	lidt [eax]
	ret
tss_setup:
	mov eax, [esp + 4]
	ltr ax
	ret
outPort:
	mov edx, [esp + 4]
	mov eax, [esp + 8]
	out dx, al
	ret
inPort:
	mov dx,[esp + 4]
	mov eax,0
	in al, dx
	ret
