; system V AMD64
; ADD, ADC (pour retenue)
; SUB, SBB (pour retenue)
; MUL, IMUL (pour valeur neg)
; DIV, IDIV (pour valeur neg)
; OF (overflow Flag)
; CF (Flag pour valeur non signee)
; leaf function ===> don't calll other function
;--------------------------------------------------------------------------

bits 64

%include "src/addnumbers.s"

%define STDOUT 1
%define STDIN 0

%define SYS_WRITE 1
%define SYS_READ 0
%define SYS_EXIT 60

%define RETURN_LINE 10		; ASCII for \n

%define SHADOW_SPACE 32		; ajoute de la place pour rdi, rsi, rdx, rcx, r8, r9

%define MAX_BUFFER 584

; extern _addnumbers
extern ft_strlen
extern ft_write
; extern atoi

global _start							; directive to export the symbol  _start for external use

section .data
	msg db 'Please enter a number, the programm return the length of it', RETURN_LINE
	len equ $-msg

section .bss
	input resb MAX_BUFFER


section .text
		_start:
			sub rsp, 8

			mov rax, SYS_WRITE
			mov rdi, STDOUT
			mov rsi, msg
			mov rdx, len
			syscall

			mov rax, SYS_READ
			mov rdi, STDIN
			mov rsi, input
			mov rdx, MAX_BUFFER
			syscall

			mov rbx, rax
			mov byte [input + rbx], 0
			mov rdi, input
			call ft_strlen

			mov rbx, rax
			mov byte [input + rbx], RETURN_LINE
			add rsp, 8
			mov rdi, input
			call ft_strlen

			mov rdi, STDOUT
			mov rsi, input
			mov rdx, rax
			call ft_write

			; exit process
			mov rax, SYS_EXIT			; call exit function
			mov rdi, STDOUT				; arg of exit function
			syscall						; calling GNU system to apply function (exit on this case)
