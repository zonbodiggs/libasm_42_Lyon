bits 64

global ft_strlen

%define NULL 0

section .text
	ft_strlen:
		mov rcx, 0								; init loop register

		_loop:
			cmp byte [rdi + rcx], NULL			; exit if str[rcx] == '\0'
			JZ _exit

			inc rcx								; increase loop register
			jmp _loop							; recall the loop
		_exit:
			mov rax, rcx						; put loop register in return register
			ret									; return rax
