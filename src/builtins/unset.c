/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:20:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/03 17:20:53 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_unset_error(char *str)
{
	ft_putstr_fd("minishell: unset: ", 2);
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\'', 2);
	ft_putendl_fd(": not a valid identifier", 2);
}

int	unset(int ac, char *av[], t_list *env_list)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_indexof(av[i], '=') != -1
			|| !is_var_name(av[i], ft_strlen(av[i])))
		{
			print_unset_error(av[i]);
			return (FT_FAILURE);
		}
		ft_unsetenv(env_list, av[i]);
		i++;
	}
	return (FT_SUCCESS);
}
