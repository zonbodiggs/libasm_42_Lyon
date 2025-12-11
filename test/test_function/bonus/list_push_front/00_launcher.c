/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:27:46 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/11 15:04:46 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	list_push_front_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &list_push_front_basic_test, false);
	load_test(&testlist, "NULL test", &list_push_front_null_test, false);
	load_test(&testlist, "One element test",
		&list_push_front_one_element_test, false);
	load_test(&testlist, "Long list test",
		&list_push_front_long_list_test, false);
	return (launch_test(testlist));
}
