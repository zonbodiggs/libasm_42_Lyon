/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_long_list_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 08:38:15 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/17 17:13:04 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

#include "libasm.h"

static void	init_list(t_list **list, int size)
{
	int		i;
	int		*value;

	i = 0;
	while (i < size)
	{
		value = malloc(2 * sizeof(int));
		if (i % 2 == 0)
			*value = 1;
		else
			*value = i + 1;
		ft_list_push_front(list, value);
		i++;
	}
	return ;
}

static void	free_fct(void *data_ptr_list)
{
	free (data_ptr_list);
}

static bool	create_and_execute(int (*cmp)(), void *data_ref, int size)
{
	t_list		*lst;
	t_list		*tmp;

	lst = NULL;
	init_list(&lst, size);
	tmp = lst;
	ft_list_remove_if(&lst, data_ref, cmp, &free_fct);
	if (is_lst_has(lst, data_ref, &compare))
		return (free(data_ref), free_list(&tmp), false);
	return (free(data_ref), free_list(&tmp), true);
}

int	list_remove_if_long_list_test(void)
{
	int			*data_ref;

	data_ref = malloc(2 * sizeof(int));
	*data_ref = 1;
	if (create_and_execute(&compare, data_ref, 65534))
		return (0);
	return (-1);
}
