/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:03:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/17 11:57:12 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int echo(int ac, char *av[])
{
	int i;
	int has_n_flag;

	i = 1;
	has_n_flag = strcmp(av[1], "-n") == 0;
	if (has_n_flag)
		i++;
	while (i < ac)
	{
		printf("%s", av[i]);
		i++;
		if (av[i])
			printf(" ");
	}
	if (!has_n_flag)
		printf("\n");
	return (0);
}
