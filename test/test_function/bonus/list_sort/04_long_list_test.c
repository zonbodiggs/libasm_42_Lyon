/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_long_list_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:48:24 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/17 10:57:09 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "time.h"

static void	init_list(t_list **list, int size)
{
	int		i;
	int		*value;

	i = 0;
	srand(time(NULL));
	while (i < size)
	{
		value = malloc(2 * sizeof(int));
		*value = rand() % 65535;
		ft_list_push_front(list, value);
		i++;
	}
	return ;
}

int	list_sort_long_list_test(void)
{
	t_list		*list;
	t_list		*tofree;

	list = NULL;
	init_list(&list, 65534);
	tofree = list;
	ft_list_sort(&list, &compare);
	if (is_list_sort(tofree, &compare))
		return (free_list(&tofree), 0);
	return (free_list(&tofree), -1);
}
