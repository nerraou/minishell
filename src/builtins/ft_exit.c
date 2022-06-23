/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:52:21 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/23 18:07:22 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void print_exit_erro(char *str)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": numeric argument required", 2);
}

void ft_exit(int ac, char *av[])
{
	int check;
	long state_num;

	state_num = 255;
	if (ac > 1)
	{
		check = is_long(av[1]);
		if (check == 1)
			state_num = ft_atol(av[1]);
		else
			print_exit_erro(av[1]);
	}
	exit(0);
}