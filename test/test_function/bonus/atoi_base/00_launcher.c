/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:27:41 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/18 09:11:08 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	atoi_base_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	printf("%sATOI BASE:%s\n", BLUE, RESET);
	load_test(&testlist, "Basic test", &atoi_base_basic_test, false);
	load_test(&testlist, "NULL test", &atoi_base_null_test, false);
	load_test(&testlist, "One element test",
		&atoi_base_one_element_test, false);
	load_test(&testlist, "Long list test",
		&atoi_base_bigger_str_test, false);
	return (launch_test(testlist));
}
