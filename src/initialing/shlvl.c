/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:26:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/06 16:41:17 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char	*env, char **envp, int *i)
{
	int j;

	if (i)
	{
		*i = 0;
		while (envp && envp[*i] && ft_strncmp(env, envp[*i], ft_strlen(env)))
			(*i)++;
		return (envp[*i] + ft_strlen(env));
	}
	else
	{
		j = 0;
		while (envp && envp[j] && ft_strncmp(env, envp[j], ft_strlen(env)))
			(j)++;
		return (envp[j] + ft_strlen(env));
	}
}

void	update_shlvl(char **envp)
{
	int	i;
	int	lvl;

	i = 0;
	while (envp && envp[i])
	{
		envp[i] = ft_strdup(envp[i]);
		i++;
	}
	lvl = ft_atoi(get_env_value("SHLVL=", envp, &i));
	lvl++;
	free(envp[i]);
	envp[i] = ft_strdup(ft_strjoin("SHLVL=", ft_itoa(lvl)));
}