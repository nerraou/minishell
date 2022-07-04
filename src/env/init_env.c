/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:02:03 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/04 18:06:42 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	handle_shlvl(t_list *env_list)
{
	char	*shelvl;
	t_env	*env;

	if (ft_getenv(env_list, "SHLVL") == NULL)
	{
		shelvl = ft_strdup("SHLVL=1");
		env = new_env(shelvl);
		add_back(env_list, env);
	}
}

static char	*join_and_free(char *s1, char *s2)
{
	char	*shelvl;

	shelvl = ft_strjoin(s1, s2);
	free(s2);
	return (shelvl);
}

t_list	*init_env(char *env_arr[])
{
	t_list	*env_list;
	t_env	*env;
	char	*shelvl;
	int		lvl;
	int		i;

	env_list = list_new();
	i = 0;
	while (env_arr[i])
	{
		env = new_env(env_arr[i]);
		if (ft_strcmp(env->key, "SHLVL") == 0)
		{
			lvl = ft_atoi(env->value);
			shelvl = join_and_free("SHLVL=", ft_itoa(lvl + 1));
			del_env(env);
			env = new_env(shelvl);
			free(shelvl);
		}
		add_back(env_list, env);
		i++;
	}
	handle_shlvl(env_list);
	return (env_list);
}
