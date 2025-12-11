bits 64

global ft_list_size

%define NULL 0

section .bss
	next : resq 1

section .text
	ft_list_size:
		push rbx
		mov rcx, 0				; init loop (equ int i = 0 in c)

		test rdi, rdi			; NULL check
		JZ	_exit
	
		mov rbx, [rdi + 8]		; add contain of struct s_list *next on rbx register 
		mov [next], rbx			; add rbx (wich contain tstruct s_list *next) on next variable

	_list_size_loop:
		inc rcx

		test rbx, rbx
		JZ	_exit

		mov rdi, [next]			; mov t_list to t_list->next
		mov rbx, [rdi + 8]		; add contain of struct s_list *next on rbx register 
		mov [next], rbx			; add rbx (wich contain tstruct s_list *next) on next variable

		JMP _list_size_loop
	_exit :
		pop rbx
		mov rax, rcx
		ret