bits 64

; %define  "stdlib.h"
; %include ""

global ft_strdup

extern malloc
extern ft_strlen

%define NULL 0

section .text
	ft_strdup:
		_prologue:						; prologue for no leaf function 
			push rbp					; add the base pointer register to stack
			mov rbp, rsp				; copy the base pointer value register on stack pointer register value

			push rbx					; save register for allocated variable
			sub rsp, 8					; save space for allocated variable on stack pointer

		call ft_strlen					; fin the len of the src  

		mov rbx, rdi	

		mov rdi, rax					; copy the len of src in rdi
		add rdi, 1						; len of src + 1
		call malloc						; malloc it

		cmp rax, NULL
		jz _error

		mov rcx, 0						; init the loop

		_loop:
			mov byte al, [rbx + rcx]	; save src[rcx] in al registre
			mov byte [rax + rcx], al	; cpy src[rcx] in dest[rcx]

			cmp byte [rbx + rcx], NULL		; finished if src[rcx] = '\0'
			jz _exit
		
		_epilogue: 					; epilogue for no leaf function 
			add rsp, 8				; restore space save in prologue
			pop rbx					; restored register save in prologue

			mov rsp, rbp			; copy the stack pointer value register on base pointer register value 
			pop rbp	
									; remove base pointer register from stack

		_error:
			call _epilogue

			mov rax, NULL
			ret
		_exit:
			call _epilogue			; restore spaces save in prologue
			ret						; return rax

			