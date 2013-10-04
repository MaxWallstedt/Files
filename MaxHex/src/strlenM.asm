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

global strlenM			; char *strlenM(char *rdi)
strlenM:
	push	rdi
	push	cx

	mov	eax, 0		; int eax = 0;
	test	rdi, rdi	; if (rdi == NULL)
	je	.quit		;     goto .quit;

.loop:
	mov	cl, [rdi]	; cl = *rdi;
	test	cl, cl		; if (cl == '\0')
	je	.quit		;     goto .quit;
	add	eax, 1		; ++eax;
	add	rdi, 1		; ++rdi;
	jmp	.loop		; goto .loop;

.quit:
	pop	cx
	pop	rdi
	ret			; return eax;
