/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_void_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:13:43 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 15:32:10 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	strdup_void_test(void)
{
	char	*dest_real;
	char	*dest_assembly;

	dest_real = strdup("");
	dest_assembly = ft_strdup("");
	if (strcmp(dest_real, dest_assembly) == 0)
		return (free(dest_assembly), free(dest_real), 0);
	return (free(dest_assembly), free(dest_real), -1);
}
