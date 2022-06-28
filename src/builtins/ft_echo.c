/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:03:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 18:24:58 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_has_n_flag(const char *str)
{
	int	i;

	if (str[0] != '-' || !str[1])
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(int ac, char *av[])
{
	int	i;
	int	has_n_flag;

	i = 1;
	has_n_flag = ft_has_n_flag(av[i]);
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
