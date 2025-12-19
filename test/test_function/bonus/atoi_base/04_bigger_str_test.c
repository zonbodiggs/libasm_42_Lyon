/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_bigger_str_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:19:24 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/19 09:05:22 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static char	*get_bigger_str(void)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(2147483648 * sizeof(char));
	while (i < 2147483647)
	{
		str[i] = 'a';
		i++;
	}
	return (str);
}

static bool	is_verif_good(char *str, char *base)
{
	if (atoi_base(str, base) == ft_atoi_base(str, base))
		return (true);
	return (false);
}

int	atoi_base_bigger_str_test(void)
{
	char	*base;
	char	*str;

	base = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@_";
	str = get_bigger_str();
	if (is_verif_good("borjQ45@", base)
		&& is_verif_good("-14Qas@cAsd", base)
		&& is_verif_good("Eposr@456", base)
		&& is_verif_good("Hello_World42", base)
		&& is_verif_good("borjQ45@", base)
		&& is_verif_good(str, base))
		return (0);
	return (-1);
}
