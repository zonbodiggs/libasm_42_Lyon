bits 64

global ft_strdup

extern malloc
extern ft_strlen
extern ft_strcpy

%define NULL 0

section .text
	ft_strdup:
		push rbx

		call ft_strlen					; find the len of the src
		mov rbx, rdi					; save rdi in rbx for futur use

		mov rdi, rax					; copy the len of src in rdi
		add rdi, 1						; len of src + 1
		call malloc						; malloc it

		cmp rax, NULL
		JE _exit

		mov rdi, rax
		mov rsi, rbx
		call ft_strcpy

		_exit:
			pop rbx
			ret						; return rax
	

			