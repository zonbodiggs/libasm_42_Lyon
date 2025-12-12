; void ft_list_sort(t_list **begin_list, int (*cmp)());
; null check of t_list**begin_list
; null check of in (*cmp)() function 
; set up t_list *begin_list (copy it in rbx)
; set up t_list *begin_list->next (copy it in next global variable)
; execute principal loop


; cmp(list->next->data, list->data) list->next->data - list->data
; list->next->data > list->data => +1
; list->next->data < list->data => -1

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
		mov rbx, [rdi + 8]		; copy *begin_list->next in rbx
		
		mov [function], rsi		; copy int (cmp)() function into function

	_sort_loop:
		test rdi, rdi			; NULL check of t_list **list
		JZ _exit

		mov rdi, rbx			; shift t_list *list (list = list->next)
		mov rbx, [rdi + 8]		; reset list->next

		mov r12, rbx			; copy list->next into next
		JMP _check_loop			; execute second loop

		JMP	_sort_loop

	_check_loop:
		test rbx, rbx
		JZ _exit 

		mov rsi, [rdi]			; copy list->data into rsi

		push rdi
		and rsp, -16
		mov rdi, [r12]			; copy list->next->data into rdi 
		call [function]			; call int (cmp)() function
		pop rdi

		cmp rax, 0				; check if value1 >/< value 2
		JG _swap				; if rax negative swap rdi and rbp

		mov r12, [r12 + 8]		; increase *list pointed by rbp

		test r12, r12			; null check of rbp
		JZ _sort_loop			; break second loop

		JMP _check_loop

	_swap:						; TO DO change swap
		mov rsi, [r12]			; *tmpa = *a
		mov r8, [rdi]

		mov r12, r8				; *a = *tmp
		mov rdi, rsi			; *b = *a

		; mov rsi, [rdi + 8]
		; mov [r12 + 8], rsi

		; mov [rdi + 8], rbx

		; mov r12, rbx

		JMP _check_loop			; recall the second loop
	
	_exit:
		pop r12
		pop rbx					; epilogue restore rbx

		ret
