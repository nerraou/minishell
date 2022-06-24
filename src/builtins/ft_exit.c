/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:52:21 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/24 09:31:16 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void print_exit_error(char *str)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": numeric argument required", 2);
}

int ft_exit(int ac, char *av[])
{
	int check;
	long state_num;

	state_num = 255;
	if (ac > 2)
	{
		printf("minishell: exit: too many arguments\n");
		return FT_FAILURE;
	}
	if (ac == 2)
	{
		check = is_long(av[1]);
		if (check == 1)
			state_num = ft_atol(av[1]);
		else
			print_exit_error(av[1]);
		exit(state_num & 255);
	}
	exit(0);
	return FT_SUCCESS;
}