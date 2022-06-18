/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:02:03 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/18 15:57:14 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_list *init_env(char *env_arr[])
{
	t_list *env_list;
	t_env *env;
	int i;

	env_list = list_new();
	i = 0;
	while (env_arr[i])
	{
		if (ft_strncmp(env_arr[i], "_=", 2) != 0)
		{
			env = new_env(env_arr[i]);
			add_back(env_list, env);
		}

		i++;
	}
	return (env_list);
}
