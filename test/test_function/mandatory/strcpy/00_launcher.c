/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:08:37 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:46:18 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	strcpy_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	printf("%sSTRCPY:%s\n", BLUE, RESET);
	load_test(&testlist, "Basic test", &strcpy_basic_test, false);
	load_test(&testlist, "NULL test", &strcpy_null_test, true);
	load_test(&testlist, "Bigger string test",
		&strcpy_bigger_string_test, false);
	load_test(&testlist, "Void string test", &strcpy_void_test, true);
	load_test(&testlist, "Void s1 test", &strcpy_void_s1_test, true);
	load_test(&testlist, "Void s2 test", &strcpy_void_s2_test, true);
	load_test(&testlist, "Bigger s1 test", &strcpy_bigger_s1_test, true);
	load_test(&testlist, "Bigger s2 test", &strcpy_bigger_s2_test, true);
	return (launch_test(testlist));
}
