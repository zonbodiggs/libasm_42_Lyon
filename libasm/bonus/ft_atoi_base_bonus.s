bits 64

global ft_atoi_base

extern ft_strlen

%define PLUS 43
%define MINUS 45
%define SPACE 32
%define HORIZONTAL_TAB 9
%define RETURN 13

section .data
	sign : db 1
	base_len : db 0

section .text
;-------------------------------------PROLOGUE------------------------------------
	ft_atoi_base:
		push rbx							; push rbx to stack

		test rdi, rdi						; check null str
		JZ _exit_error						; if str is null return 0

		test rsi, rsi						; check null base 
		JZ _exit_error						; if base is null return 0

		JMP _check_base						; label for check the base 
;----------------------------------------------------------------------------------
;-------------------------------------CHECK BASE-----------------------------------
	_check_base:
		mov rcx, 0							; set loop counter to 0
		mov byte al, [rsi + rcx]			; cpy base[0] in al register
		test al, al							; check null base[0]
		JZ _exit_error						; if base[0] is null return 0

		inc rcx								; increase rcx
		mov byte al, [rsi + rcx]			; cpy base[1] in al register
		test al, al							; check null base[1]
		JZ _exit_error						; if base[1] is null return 0

		mov rcx, 0							; reset loop counter to 0

	_check_base_loop:	
		mov byte al, [rsi + rcx]			; cpy base[rcx] in al register
		test al, al							; check null base[rcx]
		JZ _prepare_str						; jump to prepare str if base[rcx] = null

		cmp al, PLUS						; compare base[rcx] with '+'
		JE _exit_error						; if base[rcx] is '+' return 0

		cmp al, MINUS						; compare base[rcx] with '-'
		JE _exit_error						; if base[rcx] is '-' return 0

		cmp al, SPACE						; compare base[rcx] with space (' ')
		JBE _exit_error						; if base[rcx] is lower or equal to space return 0 

		mov r8, 1							; set second loop counter to 1
		add r8, rcx							; add first loop counter (rcx) to second loop counter (r8)
		JMP _check_double_loop				; Jump to the second loop (check the doule)

	_check_double_loop:	
		mov byte dl, [rsi + r8]				; cpy base[r8] in dl register
		test dl, dl							; check null base[r8]
		JZ _increase_check_loop				; if base[r8] is null increase first loop and jump to it

		cmp al, dl							; compare base[rcx] with base[r8]
		JE _exit_error						; if base[rcx] = base[r8] return 0

		inc r8								; increase r8
		JMP _check_double_loop				; jump to the second loop

	_increase_check_loop:
		inc rcx								; increase rcx
		JMP _check_base_loop				; jump to check_base_loop
;----------------------------------------------------------------------------------
;------------------------------------PREPARE STR-----------------------------------
	_prepare_str:
		mov rcx, 0							; reset counter loop to 0
		JMP _skip_whitespace_loop			; jump to skip white space label

	_skip_whitespace_loop:
		mov byte al, [rdi + rcx]			; cpy str[rcx] in al register

		cmp al, SPACE						; compare str[rcx] with space
		JE _increase_skip_whitespace_loop	; incerease rcx if str[rcx] is space

		cmp al, RETURN						; compare str[rcx] with return (13)
		JE _increase_skip_whitespace_loop	; increase if str[rcx] is return
		JB _check_horizontal_tab			; if str[rcx] lower than return check if it is greater or equal than horizontal tab
		 
		JMP _check_sign						; jump to finish prepare step

	_check_horizontal_tab:
		cmp al, HORIZONTAL_TAB				; compare str[rcx] with Horizontal tab (9)
		JAE _increase_skip_whitespace_loop	; if str[rcx] greater or equal than Horizontal tab increase loop

		JMP _check_sign						; jump to finish prepare step

	_increase_skip_whitespace_loop:
		inc rcx								; increase rcx
		JMP _skip_whitespace_loop			; jump to _skip_whitespace_loop

	_check_sign:
		mov byte al, [rdi + rcx]			; cpy str[rcx] in al register

		cmp al, PLUS						; compare str[rcx] with '+'
		JNE _chek_neg						; if not equal check if str[rcx] is '-'

		inc rcx								; increase rcx
		JMP _convert						; begin conversion

	_chek_neg:
		cmp al, MINUS						; compare str[rcx] with '-'
		JNE _convert						; if str[rcx] is '-' set sign to negative

		inc rcx								; increase rcx
		mov byte [sign], -1					; set sign to -1
;----------------------------------------------------------------------------------
;--------------------------------CONVERT TO INT BASE-------------------------------
	_convert:
		mov rbx, rsi						; copy base to rbx

		sub rsp, 8							; sub 8 to stack pointer
		push rdi							; push rdi to stack
		push rcx							; push rcx to stack
		mov rdi, rbx						; cpy base to rdi for first arg of strlen function
		call ft_strlen						; call strlen funcion
		pop rcx								; restore rcx
		pop rdi								; restore rdi
		add rsp, 8							; add 8 to stack pointer

		mov [base_len], rax					; cpy result of strlen on baselen variable
		mov rbx, 0							; set the result to 0 res = 0

	_convert_loop:
		mov byte al, [rdi + rcx]			; cpy str[rcx] in al register

		test al, al							; check null str[0]
		JZ _exit							; exit if str[0] is null

		imul rbx, [base_len]				; multiply rbx(res) by base_len

		mov r8, 0

		JMP _find_pos_loop

	_find_pos_loop:
		mov byte dl, [rsi + r8]			; cpy base[r8] in dl register	
		test dl, dl							; check null base[r8] 
		JZ _exit_error						; exit error if base[r8] is null

		cmp al, dl							; compare str[rcx] with base[r8]
		JE _add_pos_to_res					; add pos r8 to rbx if str[rcx] = base[r8]

		inc r8								; increase r8
		JMP _find_pos_loop					; remake the loop

	_add_pos_to_res:
		add rbx, r8							; add the pos of str[rcx] in the base to result register
		inc rcx								; increase first loop counter rcx
		JMP _convert_loop					; remake convert_loop
;----------------------------------------------------------------------------------
;------------------------------------EXIT FUNCTION---------------------------------
	_exit:
		mov rax, rbx						; cpy rbx (res) in rax
		pop rbx								; restore rbx
		; imul rax, [sign]					; TO DO rework sign 
		ret									; return rax
	
	_exit_error:
		pop rbx								; restore rbx
		mov rax, 0							; cpy 0 to rax (return (0))
		ret									; ret
;----------------------------------------------------------------------------------