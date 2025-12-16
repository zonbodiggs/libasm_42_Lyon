bits 64

global ft_strcmp

%define NULL 0

section .text
	ft_strcmp:
		mov rcx, 0							; init loop register

		_loop:
			mov byte al, [rdi + rcx]
			mov byte dl, [rsi + rcx]

			cmp al, dl
			JNE _exit

			test al, al						; compare s1[rcx] && s2[rcx]
			JE _exit						; jump to exit if not equal

			inc rcx							; increase loop register
			jmp _loop						; recall the loop

		_exit:
			movzx eax, al					; put s1[rcx] in return register
			movzx edx, dl
			cmp al, dl
			JL _inferior
			JG _superior

			sub eax, edx					; sub rax with s2[rcx]
			ret								; return rax

		_inferior:
			mov eax, -1
			ret

		_superior:
			mov eax, 1
			ret

