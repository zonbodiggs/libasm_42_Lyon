bits 64

global ft_list_sort

section .bss
	function : resq 1
	head	 : resq 1

section .text
	ft_list_sort:
		push rbx				; prologue save rbx (push rbx to stack)
		push r12				;  prologue save r2 (push rbx to stack)

		test rdi, rdi			; NULL check of t_list **list
		JZ _exit

		test rsi, rsi			; NULL check of int (*cmp)() function
		JZ _exit

		mov rbx, [rdi]			; copy *begin_list in rbx
		
		mov [function], rsi		; copy int (cmp)() function into function

	_sort_loop:
		mov rcx, [rdi]			; tmp = (*begin_list);
		test rcx, rcx			; NULL check of tmp
		JZ _exit

		mov rbx, [rbx + 8]		; increase begin_cmp_list (begin_cmp_list = begin_cmp_list->next)

		test rbx, rbx			; test if *begin_cmp_list = NULL
		JZ _increase_head		; if (cmp_list == NULL) jump _increase_head label
		JNZ _calling_cmp		; else if (cmp_list != NULL)  jump _calling_cmp label

		JMP _sort_loop
	
	_increase_head:
		mov rcx, [rdi]			; tmp = (*begin_list);
		mov rcx, [rcx  + 8]		; tmp = tmp->next;

		mov [rdi], rcx			; *begin_list = tmp;
		mov rbx, [rdi]			; cmp_list = (*begin_list);
		jmp _sort_loop

	_swap:
		mov rcx, [rdi]			; tmp = (*begin_list);
		mov r12, [rcx]			; copy tmp->data into r12
		mov r8, [rbx]			; copy begin_cmp_list->data into r8

		mov [rcx], r8			; copy r8 into tmp->data
		mov [rbx], r12			; copy r12 into begin_cmp_list->data

		jmp _sort_loop

	_calling_cmp:
		mov rcx, [rdi]			; tmp = (*begin_list);
		mov r12, [rcx]			; save value of tmp->data
		sub rsp, 8
		push rdi				; push rdi to stack
		mov rdi, r12			; copy tmp->data into rdi first arg
		mov rsi, [rbx]			; copy cmp_list->data into rsi second arg
		call [function]			; calling cmp function
		pop rdi					; restore rdi to stack
		add rsp, 8

		cmp eax, 0				; check comparaison of value1 and value2 use eax because of non signe value
		JG _swap				; jump to swap if greater value1 > value2
		jmp _sort_loop			; return to sort loop

	_exit:
		pop r12					; epilogue restore r12
		pop rbx					; epilogue restore rbx

		ret
