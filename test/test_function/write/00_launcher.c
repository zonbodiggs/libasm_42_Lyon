/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:19:38 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:20:14 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	write_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	printf("%sWRITE:%s\n", BLUE, RESET);
	load_test(&testlist, "Basic test", &write_basic_test, false);
	load_test(&testlist, "Wrong fd test", &write_null_test, false);
	load_test(&testlist, "Bigger string test",
		&write_bigger_string_test, false);
	return (launch_test(testlist));
}
