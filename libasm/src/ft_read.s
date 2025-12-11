bits 64

global ft_read

extern __errno_location

%define NULL 0
%define SYS_READ 0

section .text
	ft_read:
		mov rax, SYS_READ			; call the sys_read function 
		syscall
		cmp rax, NULL
		JL _error
		ret

	_error:
		neg rax						; get absolute value of rax
		mov rdi, rax				; add rax in arg of errno location 
		call __errno_location
		mov [rax], rdi				; set value of errno
		mov rax, -1
		ret