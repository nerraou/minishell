/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:20:21 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/30 08:16:36 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_env(char	*vrb, char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i] && ft_strncmp(vrb, envp[i], ft_strlen(vrb)))
		i++;
	if (envp[i])
		return (i);
	return (0);
}

char	*get_env_value(char	*env, char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i] && ft_strncmp(env, envp[i], ft_strlen(env)))
		i++;
	if (envp[i])
		return (ft_strdup(envp[i] + ft_strlen(env)));
	return (ft_substr(env, 0, ft_strlen(env) - 1));
}
