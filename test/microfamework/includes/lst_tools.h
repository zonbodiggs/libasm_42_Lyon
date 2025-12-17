/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 08:38:49 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/17 11:07:56 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_TOOLS_H
# define LST_TOOLS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

				/*********list tools*********/
void	lst_add_back(t_list **testlist, t_list *new);
t_list	*lst_new(void *data);
int		list_size(t_list *begin_list);
void	free_list(t_list **list);

void	list_sort(t_list **begin_list, int (*cmp)());
bool	is_list_sort(t_list *begin_list, int (*cmp)());

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *));
bool	is_lst_has(t_list *begin_list, void *data_ref, int (*cmp)());

int		compare(void *a, void *b);

#endif