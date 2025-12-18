/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_one_element_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 08:37:57 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/18 08:15:56 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	free_fct(void *data_ptr_list)
{
	free (data_ptr_list);
}

static int	compare(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

static bool	create_and_execute(int (*cmp)(), void *data_ref)
{
	t_list		*lst;
	t_list		*tmp;
	int			*data;

	lst = NULL;
	tmp = lst;
	data = malloc(2 * sizeof(int));
	*data = 1;
	ft_list_push_front(&lst, data);
	ft_list_remove_if(&lst, data_ref, cmp, &free_fct);
	if (is_lst_has(lst, data_ref, &compare))
		return (free(data_ref), free_list(&tmp), false);
	return (free(data_ref), free_list(&tmp), true);
}

int	list_remove_if_one_element_test(void)
{
	int			*data_ref;

	data_ref = malloc(2 * sizeof(int));
	*data_ref = 1;
	if (create_and_execute(&compare, data_ref))
		return (0);
	return (-1);
}
