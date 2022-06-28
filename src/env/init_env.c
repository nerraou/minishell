/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:02:03 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 18:25:09 by obelkhad         ###   ########.fr       */
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
			shelvl = ft_strjoin("SHLVL=", ft_itoa(lvl + 1));
			del_env(env);
			env = new_env(shelvl);
		}
		add_back(env_list, env);
		i++;
	}
	handle_shlvl(env_list);
	return (env_list);
}
