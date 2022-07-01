/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:53:34 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/01 15:06:32 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char	*cmd)
{
	if (cmd)
	{
		if (!ft_strncmp(cmd, "cd", ft_strlen(cmd)))
			return (1);
		if (!ft_strncmp(cmd, "echo", ft_strlen(cmd)))
			return (2);
		if (!ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
			return (3);
		if (!ft_strncmp(cmd, "export", ft_strlen(cmd)))
			return (4);
		if (!ft_strncmp(cmd, "unset", ft_strlen(cmd)))
			return (5);
		if (!ft_strncmp(cmd, "env", ft_strlen(cmd)))
			return (6);
		if (!ft_strncmp(cmd, "exit", ft_strlen(cmd)))
			return (7);
	}
	return (0);
}

int	exe_builtin(int built, t_cmd *cmd, t_list *env_)
{
	if (built == 1)
		return (cd(cmd->num_of_args - 1, cmd->args, env_));
	if (built == 2)
		return (ft_echo(cmd->num_of_args - 1, cmd->args));
	if (built == 3)
		return (pwd());
	if (built == 4)
		return (export(cmd->num_of_args - 1, cmd->args, env_));
	if (built == 5)
		return (unset(cmd->num_of_args - 1, cmd->args, env_));
	if (built == 6)
		return (env(env_));
	if (built == 7)
		return (ft_exit(cmd->num_of_args - 1, cmd->args));
	return (1);
}
