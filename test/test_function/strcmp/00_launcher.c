/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:01:53 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:39:25 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	strcmp_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	printf("%sSTRCMP:%s\n", BLUE, RESET);
	load_test(&testlist, "Basic test", &strcmp_basic_test, false);
	load_test(&testlist, "Diff test", &strcmp_diff_test, false);
	load_test(&testlist, "NULL test", &strcmp_null_test, true);
	load_test(&testlist, "Bigger string test",
		&strcmp_bigger_string_test, false);
	load_test(&testlist, "Void string test", &strcmp_void_test, false);
	load_test(&testlist, "Void s1 test", &strcmp_void_s1_test, false);
	load_test(&testlist, "Void s2 test", &strcmp_void_s2_test, false);
	load_test(&testlist, "Bigger s1 test", &strcmp_bigger_s1_test, false);
	load_test(&testlist, "Bigger s2 test", &strcmp_bigger_s2_test, false);
	return (launch_test(testlist));
}
