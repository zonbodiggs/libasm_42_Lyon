/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:54:21 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/11 12:04:14 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "launcher.h"

void		lstadd_back(t_test **testlist, t_test *new);
size_t		lst_size(t_test *testlist);
void		free_test_list(t_test **testlist);
void		free_one_element(t_test **testlist);

#endif