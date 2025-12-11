bits 64

; t_list **list = rdi
; t_list *list = [rdi] 
; t_list (*list)->data = [rdi + 0]
; t_list (*list)->next = [[rdi] + 8]

global ft_list_push_front

extern malloc

%define NULL 0

section .bss
	data : resq 8
	next : resq 8
	head : resq 8

section .text
	ft_list_push_front:
		push rbx
		push rdi

		test rdi, rdi					; test if t_list **begin_list is NULL
		JZ _exit

		mov rbx, [rdi]					; add *list (head of the list) on rbx register
		mov [head], rbx					; save contain of *list (head of the list) on the adrr of head value

		mov rbx, [head + 8]				; add *list->next on rbx register
		mov [next], rbx					; save the contain of *list->next on  the adrr of next value

		mov [data], rsi					; add void *data passed in parameter to data asm to save it

		mov rdi, 16						; arg of malloc 8 bits
		call malloc						; malloc one list

		test rax, rax
		JZ _exit

		mov [rax + 0], rsi				; add void *data to data pointed by *new 
		mov rbx, [head] 				; add old head to rbx register
		mov [rax + 8], rbx				; set the next of t_list *new to old head 		

		pop rdi
		mov [rdi], rax					; set the new head of list to new list allocate
	_exit:
		pop rbx
		
		ret