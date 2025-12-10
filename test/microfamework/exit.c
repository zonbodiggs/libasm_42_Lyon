/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:44:47 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:26:25 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"
#include "tools.h"

void	exit_error(t_test *testlist)
{
	free_list(&testlist);
	exit(-1);
}

void	free_and_return(t_test *testlist)
{
	free(testlist);
	return ;
}
