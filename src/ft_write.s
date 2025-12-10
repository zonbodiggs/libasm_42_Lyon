bits 64

global ft_write

extern ___error

%define NULL 0
%define SYS_WRITE 1

section .text
	ft_write:
		mov rax, SYS_WRITE		; call the sys_write function 
		syscall
		ret
		; jc _error				; call _error if carrry flag is set
	; _error:
	; 	mov rax, -1
	; 	ret