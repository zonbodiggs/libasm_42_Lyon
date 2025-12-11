bits 64

; t_list **list = rdi
; t_list *list = [rdi] 
; t_list (*list)->data = [rdi + 0]
; t_list (*list)->next = [[rdi] + 8]

global ft_list_push_front

extern malloc

%define NULL 0

section .bss
	data : resq 1
	next : resq 1
	head : resq 1

section .text
	ft_list_push_front:
		push rbx

		test rdi, rdi					; test if t_list **begin_list is NULL
		JZ _exit

		mov rbx, [rdi]					; add *list (head of the list) on rbx register
		mov [head], rbx					; save contain of *list (head of the list) on the adrr of head value

		mov rbx, [head + 8]				; add *list->next on rbx register
		mov [next], rbx					; save the contain of *list->next on  the adrr of next value

		mov [data], rsi					; add void *data passed in parameter to data asm to save it

		mov rdi, 8						; arg of malloc 8 bits
		call malloc						; malloc one list

		mov rbx, rax					; add result of malloc (*new) on rax
		mov byte [rbx], data			; add data on new->next
		mov byte [rbx + 8], head		; set new->next to head of **list

		mov [head], rbx					; set the new head of list to new list allocate
	_exit:
		pop rbx
		ret