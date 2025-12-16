bits 64

global ft_list_sort

section .bss
	function : resq 1

section .text
	ft_list_sort:
		push rbx				; prologue save rbx (push rbx to stack)
		push r12

		test rdi, rdi			; NULL check of t_list **list
		JZ _exit

		test rsi, rsi			; NULL check of int (*cmp)() function
		JZ _exit

		mov rdi, [rdi]			; transform **begin_list into *begin_list into rbx
		mov rbx, rdi			; copy *begin_list in rbx
		
		mov [function], rsi		; copy int (cmp)() function into function

	_sort_loop:
		test rdi, rdi
		JZ _exit

		mov rbx, [rbx + 8]		; increase begin_cmp_list (begin_cmp_list = begin_cmp_list->next)

		test rbx, rbx			; test if *begin_cmp_list = NULL
		JZ _increase_head		; if (cmp_list == NULL) jump _increase_head label
		JNZ _calling_cmp		; else if (cmp_list != NULL)  jump _calling_cmp label

		JMP _sort_loop
	
	_increase_head:
		mov rdi, [rdi + 8]		; (*begin_list) = (*begin_list)->next;
		mov rbx, rdi			; cmp_list = (*begin_list);
		jmp _sort_loop

	_swap:
		mov r12, [rdi]			; copy beginlist->data into r12
		mov r8, [rbx]			; copy begin_cmp_list->data into r8

		mov [rdi], r8			; copy r8 into beginlist->data
		mov [rbx], r12			; copy r12 into begin_cmp_list->data

		jmp _sort_loop

	_calling_cmp:
		mov r12, [rdi]			; save value of (*begin_list)->data
		push rdi				; push rdi to stack
		mov rdi, r12			; copy (*begin_list)->data into rdi first arg
		mov rsi, [rbx]			; copy cmp_list->data into rsi second arg
		call [function]			; calling cmp function
		pop rdi					; restore rdi to stack

		cmp eax, 0				; check comparaison of value1 and value2 use eax because of non signe value
		JG _swap				; jump to swap if greater value1 > value2
		jmp _sort_loop			; return to sort loop

	_exit:
		pop r12
		pop rbx					; epilogue restore rbx

		ret
