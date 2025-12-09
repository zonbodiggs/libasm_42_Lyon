; RET (return)
;	depile (sur rsp) et le placer dans RIP
;	faire un saut sur l'adresse de RIP
bits 64

; global _addnumbers
%define NULL 0
; section .data
; 	n1 db 4
; 	n2 db 6

section .text
; FONCTION _addnumbers(Entier a, Entier b)
; Entier c
; c = a + b
; return c
	; _addnumbers:
	; 	; prologue pour fonction non feuille
	; 	push rbp
	; 	mov rsp, rbp

	; 	push rbx				; sauvegarde registre pour c
	; 	sub rsp, 8				; reserve espace pour variable c

	; 	; corps de la fonction
	; 	mov rbx, qword [rbp + 16]		; rbx = a
	; 	add rbx, qword [rbp + 24]		; rbx = rbx + b
	; 	mov qword [rbp - 16], rbx		; c = rbx => [rbp - 16]
	; 	mov rax, [rbp - 16]				; rax = c

	; 	; epilogue pour fonction non feuille
	; 	add rsp, 8
	; 	pop rbx					; retablie registre
		
	; 	mov rbp, rsp
	; 	pop rbp

	; 	;return 
	; 	ret

; FONCTION _addnumbers(Entier a, Entier b)
; return a + b
	; add_numbers:
	; 	mov rax, rdi
	; 	add rax, rsi
	; 	ret

; FONCTION ft_strlen(const Char *str);
; Entier len = 0
; Boucle tant que str[len] => len + 1
; return len
	ft_strlen:
		mov rcx, 0

		_loop:
			cmp byte [rdi + rcx], NULL
			JZ _exit

			inc rcx
			jmp _loop
		_exit:
			mov rax, rcx
			ret						; return rax
		
	ft_write:
		

; FONCTION ft_strcmp(const char* s1, const char* s2)
;
;
;
	; ft_strcmp:
	; ft_atoi:
