bits 64

global ft_read

extern ___error

%define NULL 0
%define SYS_READ 0

section .text
	ft_read:
		mov rax, SYS_READ			; call the sys_read function 
		syscall
		ret
	; _error:
	; 	mov rax, -1					; call _error if carrry flag is set
	; 	ret