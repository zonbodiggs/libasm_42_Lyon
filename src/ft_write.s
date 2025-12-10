bits 64

global ft_write

extern __errno_location

%define NULL 0
%define SYS_WRITE 1

section .text
	ft_write:
		mov rax, SYS_WRITE		; call the sys_write function 
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