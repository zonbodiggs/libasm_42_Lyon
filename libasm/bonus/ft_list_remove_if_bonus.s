; void	list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
bits 64

global ft_list_remove_if

extern free

section .bss
	free_fct : resq 1
	cmp_fct : resq 1

section .text
	ft_list_remove_if:
		push rbx
		
		test rdi, rdi		; check NULL **begin_list
		JZ _exit

		test rsi, rsi		; check NULL void *data_ref
		JZ _exit

		test rdx, rdx		; check NULL int (*cmp)()
		JZ _exit

		test rcx, rcx		; check NULL void (*free_fct)(void *)
		JZ _exit 

		mov [cmp_fct], rdx	; save int (*cmp)() in global variable cmp_fct
		mov [free_fct], rcx	; save void (*free_fct)(void *) in global variable free_fct

	_loop:
		mov rdx, [rdi]		; copy *begin_list into rdx
		test rdx, rdx		; check NULL rdx is *begin_list == NULL ?
		JZ _exit			; exit if rdx is NULL

		mov rbx, [rdx]		; copy (*begin_list)->data into rbx
		test rbx, rbx		; check NULL rbx is (*begin_list)->data == NULL
		JNZ _calling_cmp	; calling cmp if (*begin_list)->data != NULL

		JMP _increase_loop	; increase *begin_list *begin_list = (*begin_list)->next;
	
	_calling_cmp:
		sub rsp, 8			; shift stack pointer align to 16 
		push rdi			; push rdi to stack
		mov rdi, rbx		; save tmp->data in first arg
		mov rsi, rsi		; add void *data_ref is second arg	
		call [cmp_fct]		; call cmp function
		pop rdi				; restor rdi
		add rsp, 8			; restore stack pointer

		cmp rax, 0			; check result of cmp fonction	
		JE	_free			; free it if result of cmp = 0
		JMP _increase_loop	; increase loop if result of cmp not 0

	_free:
		sub rsp, 8			; shift stack pointer align to 16 
		push rdi			; push rdi to stack
		mov rdi, rbx		; put the first arg of free_fct in rdi
		call [free_fct]		; call void (*free_fct)(void *)
		pop rdi				; restore rdi
		add rsp, 8			; restore stack pointer

		mov rdx, [rdi]
		mov qword [rdx], 0
		JMP _increase_loop	; increase loop after free

	_increase_loop:
		mov rdx, [rdx + 8]
		mov [rdi], rdx
		JMP _loop

	_exit:
		pop rbx
		ret
