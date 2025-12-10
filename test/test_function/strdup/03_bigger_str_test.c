/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bigger_str_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:16:10 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 15:25:24 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static char	*get_big_str(void)
{
	char		*res;
	long long	i;

	res = malloc(2147483648 * sizeof(char));
	i = 0;
	while (i < 2147483647)
	{
		res[i] = 'a';
		i++;
	}
	res[i++] = '\0';
	return (res);
}

int	strdup_bigger_string_test(void)
{
	char	*src;
	char	*dest_real;
	char	*dest_assembly;

	src = get_big_str();
	dest_real = strdup(src);
	dest_assembly = ft_strdup(src);
	if (strcmp(dest_real, dest_assembly) == 0)
		return (free(src), free(dest_real), free(dest_assembly), 0);
	return (free(src), free(dest_real), free(dest_assembly), -1);
}
