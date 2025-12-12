/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 08:38:49 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/12 08:40:38 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_TOOL_H
# define LST_TOOL_H

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

#endif