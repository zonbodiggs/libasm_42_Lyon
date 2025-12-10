bits 64

global ft_strcpy

%define NULL 0

section .text
	ft_strcpy:
		mov rcx, 0								; init loop register

		cmp byte [rsi + rcx], NULL				; if *src == '\0' return
		JZ _exit

		_loop:
			mov byte al, [rsi + rcx]
			mov byte [rdi + rcx], al			; copy src[rcs] into dest[rcx]

			cmp byte [rsi + rcx], NULL			; check if src[rcx] != '\0'
			JZ _exit

			inc rcx								; increase rcx
			JMP _loop							; recall the loop
		_exit:
			mov rax, rdi						; put dest on rax register
			ret									; return