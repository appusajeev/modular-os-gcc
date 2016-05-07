[bits 32]
[global isr_0]
[global isr_1]
[global isr_2]
[global isr_3]
[global isr_4]
[global isr_5]
[global isr_6]
[global isr_7]
[global isr_8]
[global isr_9]
[global isr_10]
[global isr_11]
[global isr_12]
[global isr_13]
[global isr_14]
[global isr_timer]
[global isr_kbd]


[extern ticks]
[extern div_zero]
[extern single_step]
[extern NMI]
[extern breakPoint]
[extern overflow]
[extern bound]
[extern undef_opcode]
[extern coproc_NA]
[extern double_fault]
[extern coproc_seg_overrun]
[extern invalid_tss]
[extern seg_absent]
[extern stack_seg_overrun]
[extern gpf]
[extern pageFault]

[extern kbd_handler]
[extern timer_handler]

isr_0:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call div_zero
	pop eax
	popa
	add esp, 4
	hlt
	iret


	
isr_1:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call single_step
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_2:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call NMI
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_3:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call breakPoint
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_4:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call overflow
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_5:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call bound
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_6:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call undef_opcode
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_7:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call coproc_NA
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_8:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call double_fault
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_9:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call coproc_seg_overrun
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_10:
	;push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call invalid_tss
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_11:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call seg_absent
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_12:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call stack_seg_overrun
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_13:
	;push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call gpf
	pop eax
	popa
	add esp, 4
	hlt
	iret
isr_14:
	push 0		;error code
	pusha			;all registers
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call pageFault
	pop eax
	popa
	add esp, 4
	hlt
	iret

isr_kbd:
	cli
	call kbd_handler
	sti
	iret
	
isr_timer:
	cli
	inc dword [ticks]

	push 0
	pusha
	xor eax,eax
	mov ax,ds
	push eax		;;ds
	call timer_handler
	pop eax
	popa
	add esp, 4
	sti
	iret
	

 

