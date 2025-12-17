/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:27:35 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/17 10:28:27 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	list_sort_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	printf("%sLIST SORT:%s\n", BLUE, RESET);
	load_test(&testlist, "Basic test", &list_sort_basic_test, false);
	load_test(&testlist, "NULL test", &list_sort_null_test, false);
	load_test(&testlist, "One element test",
		&list_sort_one_element_test, false);
	load_test(&testlist, "Long list test", &list_sort_long_list_test, false);
	load_test(&testlist, "Already sort test",
		&list_sort_long_already_sort, false);
	return (launch_test(testlist));
}
