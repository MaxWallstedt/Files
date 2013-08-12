section .text
	global main
	extern printf

main:
	mov	al, 0
	mov	edi, HelloStr	; Arg 1 = HelloStr
	call	printf

	mov     al, 60		; sys_exit
	cdq			; Sign-extend eax into edi (Arg 1 = 0)
	syscall

section .data
HelloStr:
	db	"Hello, World!", 0x0A, 0x00
