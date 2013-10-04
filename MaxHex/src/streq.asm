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

extern strlenM

global streq			; int streq(char *str1, char *str2)
streq:
	push	rbx
	push	rcx
	push	rdi
	push	rsi

	test	rdi, rdi	; if (str1 == NULL)
	je	.quitne		;     goto .quitne;

	test	rsi, rsi	; if (str2 == NULL)
	je	.quitne		;     goto .quitne;

	call	strlenM		; int str1_len = strlenM(str1);
	mov	ebx, eax	; // move str1_len to eax

	mov	rcx, rdi	; // temporarily store str1 in rcx
	mov	rdi, rsi	; // move str2 to rdi (arg1 of strlenM)
	call	strlenM		; int str2_len = strlenM(str2);
	mov	rdi, rcx	; // restore str1 to rdi

	cmp	eax, ebx	; if (str1_len != str2_len)
	jne	.quitne		;     goto .quitne;

.loop:
	mov	al, [rdi]
	test	al, al		; if (*str1 == '\0')
	je	.quiteq		;     goto .quiteq;

	cmp	al, [rsi]	; if (*str1 != *str2)
	jne	.quitne		;     goto .quitne;

	add	rdi, 1		; ++str1;
	add	rsi, 1		; ++str2;
	jmp	.loop		; goto loop;

.quitne:
	xor	eax, eax	; eax = 0;
	jmp	.quit

.quiteq:
	mov	eax, 1		; eax = 1;

.quit:
	pop	rsi
	pop	rdi
	pop	rcx
	pop	rbx
	ret			; return eax;
