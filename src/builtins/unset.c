/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:20:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/20 17:19:32 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int unset(int ac, char *av[], t_list *env_list)
{
	int i;

	i = 1;
	while (i < ac)
	{
		ft_unsetenv(env_list, av[i]);
		i++;
	}
	return 0;
}