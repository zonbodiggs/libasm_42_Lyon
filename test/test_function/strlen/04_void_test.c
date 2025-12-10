/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_void_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:19:01 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:19:24 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	strlen_void_test(void)
{
	char	*str;

	str = "";
	if (strlen(str) == ft_strlen(str))
		return (0);
	return (-1);
}
