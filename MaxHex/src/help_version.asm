; Copyright (C) 2013 Max Wällstedt
; This file is part of MaxHex.
;
; MaxHex is free software: you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation, either version 3 of the License, or
; (at your option) any later version.
;
; MaxHex is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.
;
; You should have received a copy of the GNU General Public License
; along with MaxHex.  If not, see <http://www.gnu.org/licenses/>.

global print_help		; void print_help(char *invok, int len)
print_help:
	push	rax
	push	rdx
	push	rdi
	push	rsi

	push	rsi
	push	rdi

	mov	rax, 1		; sys_write
	mov	rdi, 1		; stdout
	mov	rsi, msg1	; string address
	mov	rdx, msg1_len	; string length
	syscall

	mov	rax, 1		; sys_write
	pop	rsi
	pop	rdx
	syscall

	mov	rax, 1		; sys_write
	mov	rsi, msg2
	mov	rdx, msg2_len
	syscall

	pop	rsi
	pop	rdi
	pop	rdx
	pop	rax

	ret

msg1:
	db	"Usage:", 0x0A
	db	0x09, "$ "

msg1_len:	equ	$-msg1

msg2:
	db	" [options] <file>", 0x0A, 0x0A
	db	"Valid options:", 0x0A
	db	0x09, "-h / --help", 0x09
	db	"Print this help message", 0x0A
	db	0x09, "-v / --version", 0x09
	db	"Print version and copyright information", 0x0A
	db	0x09, "-a / --address", 0x09
	db	"Specify address to open file at", 0x0A

msg2_len:	equ	$-msg2

global print_version
print_version:
	mov	rax, 1
	mov	rdi, 1
	mov	rsi, msg
	mov	rdx, msg_len
	syscall
	ret

msg:
	db	"MaxHex version 1.0", 0x0A
	db	"Copyright (C) 2013 Max W", 0xC3, 0xA4, "llstedt", 0x0A
	db	"This program is free software; you may "
	db	"redistribute it under the terms of", 0x0A
	db	"the GNU General Public License version 3 or "
	db	"(at your opinion) a later version.", 0x0A
	db	"This program has absolutely no warranty.", 0x0A

msg_len:	equ $-msg
