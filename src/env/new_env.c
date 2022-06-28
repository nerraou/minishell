/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:33:19 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 11:36:27 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*new_env(const char *env_value)
{
	t_env	*env;
	int		equal_index;

	env = (t_env *)ft_malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	equal_index = ft_indexof(env_value, '=');
	env->prepared = ft_strdup(env_value);
	env->key = ft_substr(env_value, 0, equal_index);
	env->value = ft_strdup(env_value + equal_index + 1);
	return (env);
}
