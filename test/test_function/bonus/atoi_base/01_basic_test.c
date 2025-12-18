/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:17:07 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/18 16:15:45 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static bool	is_verif_good(char *str, char *base)
{
	if (atoi_base(str, base) == ft_atoi_base(str, base))
		return (true);
	return (false);
}

int	atoi_base_basic_test(void)
{
	if (is_verif_good("45421", "0123456789")
		&& is_verif_good("7457", "0123456789")
		&& is_verif_good("140A72", "0123456789ABCDEF")
		&& is_verif_good("FF15EA", "0123456789ABCDEF")
		&& is_verif_good("00010001", "01") && is_verif_good("11111111", "01")
		&& is_verif_good("42a", "0123456789ab")
		&& is_verif_good("a7b4", "0123456789ab"))
		return (0);
	return (-1);
}
