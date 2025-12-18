/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:20:41 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/18 16:11:28 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

bool	check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (!base[i] || !base[i + 1])
		return (false);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (false);
		if (base[i] <= 32)
			return (false);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_space(char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (true);
	return (false);
}

int	fint_pos(char c, char *base)
{
	int		pos;

	pos = 0;
	while (base[pos])
	{
		if (c == base[pos])
			return (pos);
		pos++;
	}
	return (-1);
}

bool	is_sign(char c, int *sign)
{
	if (c == '+')
		return (true);
	else if (c == '-')
	{
		(*sign) = -1;
		return (true);
	}
	return (false);
}

int	atoi_base(char *str, char *base)
{
	int		res;
	int		base_len;
	int		sign;
	int		pos;

	if (!str || !base)
		return (0);
	if (!check_base(base))
		return (0);
	while (is_space(*str))
		str++;
	sign = 1;
	if (is_sign(*str, &sign))
		str++;
	base_len = ft_strlen(base);
	res = 0;
	pos = 0;
	while (*str)
	{
		res *= base_len;
		pos = fint_pos(*str, base);
		if (pos == -1)
			return (0);
		res += pos;
		str++;
	}
	return (res * sign);
}
