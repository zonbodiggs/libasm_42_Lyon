/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:17:00 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:17:21 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	strlen_basic_test(void)
{
	if (strlen("Hello World!") == ft_strlen("Hello World!"))
		return (0);
	return (-1);
}
