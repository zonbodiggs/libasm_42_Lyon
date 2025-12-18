/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 08:37:39 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/18 08:13:01 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	compare(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

int	list_remove_if_null_test(void)
{
	t_list		*lst;
	t_list		*tmp;
	int			*data_ref;

	data_ref = malloc(2 * sizeof(int));
	*data_ref = 1;
	lst = NULL;
	ft_list_remove_if(&lst, NULL, &compare, &free_fct);
	init_list(&lst, 15);
	tmp = lst;
	ft_list_remove_if(&lst, NULL, &compare, &free_fct);
	lst = tmp;
	ft_list_remove_if(&lst, data_ref, NULL, &free_fct);
	lst = tmp;
	ft_list_remove_if(&lst, data_ref, &compare, NULL);
	ft_list_remove_if(NULL, NULL, NULL, NULL);
	lst = tmp;
	return (free_list(&lst), free(data_ref), 0);
}
