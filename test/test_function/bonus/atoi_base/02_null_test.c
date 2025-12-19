/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:18:36 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/19 09:04:44 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	atoi_base_null_test(void)
{
	char	*str;
	char	*base;

	str = NULL;
	base = NULL;
	if (ft_atoi_base(str, "0123456789") == 0
		&& ft_atoi_base("123", base) == 0
		&& ft_atoi_base(str, base) == 0)
		return (0);
	return (-1);
}
