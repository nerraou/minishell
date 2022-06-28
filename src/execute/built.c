/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:53:34 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 17:54:01 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char	*cmd)
{
	if (cmd)
	{
		if (!ft_strncmp(cmd, "cd", 2))
			return (1);
		if (!ft_strncmp(cmd, "echo", 4))
			return (2);
		if (!ft_strncmp(cmd, "pwd", 3))
			return (3);
		if (!ft_strncmp(cmd, "export", 6))
			return (4);
		if (!ft_strncmp(cmd, "unset", 5))
			return (5);
		if (!ft_strncmp(cmd, "env", 3))
			return (6);
		if (!ft_strncmp(cmd, "exit", 3))
			return (7);
	}
	return (0);
}

void	exe_builtin(int built, t_cmd *cmd, t_list *env_)
{
	if (built == 1)
		cd(cmd->num_of_args - 1, cmd->args, env_);
	if (built == 2)
		ft_echo(cmd->num_of_args - 1, cmd->args);
	if (built == 3)
		pwd();
	if (built == 4)
		export(cmd->num_of_args - 1, cmd->args, env_);
	if (built == 5)
		unset(cmd->num_of_args - 1, cmd->args, env_);
	if (built == 6)
		env(env_);
	if (built == 7)
		ft_exit(cmd->num_of_args - 1, cmd->args);
}
