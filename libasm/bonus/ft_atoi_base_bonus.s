bits 64

global ft_atoi_base

section .data

%define PLUS 42
%define MINUS 45
%define NULL 0

section .text
	ft_atoi_base:
		ret