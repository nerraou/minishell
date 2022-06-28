/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:26:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 11:13:57 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	lvl = ft_atoi(get_env_value("SHLVL=", envp));
	lvl++;
	i = check_env("SHLVL=", envp);
	free(envp[i]);
	envp[i] = ft_strdup(ft_strjoin("SHLVL=", ft_itoa(lvl)));
}
