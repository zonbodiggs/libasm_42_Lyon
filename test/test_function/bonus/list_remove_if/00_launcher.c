/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:27:50 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/17 10:47:23 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	list_remove_if_launcher(void)
{
	t_test		*testlist;

	testlist = NULL;
	printf("%sLIST REMOVE IF:%s\n", BLUE, RESET);
	load_test(&testlist, "Basic test", &list_remove_if_basic_test, false);
	load_test(&testlist, "Null test", &list_remove_if_null_test, false);
	load_test(&testlist, "One element test",
		&list_remove_if_one_element_test, false);
	load_test(&testlist, "Long list test",
		&list_remove_if_long_list_test, false);
	return (launch_test(testlist));
}
