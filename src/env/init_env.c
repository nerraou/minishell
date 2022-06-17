/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:02:03 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/17 17:32:37 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_list *init_env(char *env_arr[])
{
	t_list *env_list;
	t_env *env;
	int i;
	int equal_index;

	env_list = list_new();
	i = 0;
	while (env_arr[i])
	{
		env = (t_env *)ft_malloc(sizeof(t_env));
		if (!env)
			return NULL;
		env->prepared = ft_strdup(env_arr[i]);
		equal_index = ft_indexof(env_arr[i], '=');
		env->key = ft_substr(env_arr[i], 0, equal_index);
		env->value = ft_strdup(env_arr[i] + equal_index + 1);
		add_back(env_list, env);
		i++;
	}
	return (env_list);
}
