bits 64

global ft_strcmp

%define NULL 0

section .text
	ft_strcmp:
		mov rcx, 0							; init loop register

		_loop:
			cmp byte [rdi + rcx], NULL		; exit if s1[rcx] == '\0'
			JZ _exit

			cmp byte [rsi + rcx], NULL		; exit if s2[rcx] == '\0'
			JZ _exit
	
			mov byte al, [rdi + rcx]
			cmp byte al, [rsi + rcx]		; compare s1[rcx] && s2[rcx]
			JNZ _exit						; jump to exit if not equal

			inc rcx							; increase loop register
			jmp _loop						; recall the loop
		_exit:
			movzx rax, byte [rdi + rcx]		; put s1[rcx] in return register
			movzx rbx, byte [rsi + rcx]
			sub rax, rbx					; sub rax with s2[rcx]
			ret								; return rax