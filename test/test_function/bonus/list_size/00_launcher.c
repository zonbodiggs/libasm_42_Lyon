/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:53:21 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/11 12:08:49 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	list_size_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	printf("%sLIST SIZE:%s\n", BLUE, RESET);
	load_test(&testlist, "Basic test", &list_size_basic_test, false);
	load_test(&testlist, "NULL test", &list_size_null_test, false);
	load_test(&testlist, "One element test",
		&list_size_one_element_test, false);
	load_test(&testlist, "Long list test", &list_size_long_list_test, false);
	return (launch_test(testlist));
}
