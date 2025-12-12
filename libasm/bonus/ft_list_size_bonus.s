bits 64

global ft_list_size

%define NULL 0

section .text
	ft_list_size:
		push rbx				; prologue save rbx

		test rdi, rdi			; NULL check
		JZ	_exit

		mov rbx, [rdi + 8]		; add contain of struct s_list *next on rbx register 

		mov rcx, 0				; init loop (equ int i = 0 in c)

	_list_size_loop:
		inc rcx

		test rbx, rbx
		JZ	_exit

		mov rdi, rbx			; mov t_list to t_list->next
		mov rbx, [rdi + 8]		; add contain of struct s_list *next on rbx register 

		JMP _list_size_loop
	_exit :
		pop rbx					; epilogue restore rbx
		mov rax, rcx			; set response
		ret