/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:53:34 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/02 18:04:18 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	to_lower(char *cmd)
{
	int		i;

	i = 0;
	while (cmd && cmd[i])
	{
		cmd[i] = ft_tolower(cmd[i]);
		i++;
	}
}

int	is_builtin(char	*cmd)
{
	char	*lower;
	int		val;

	val = 0;
	if (cmd)
	{
		lower = ft_strdup(cmd);
		if (!ft_strncmp(lower, "export", ft_strlen(lower)))
			val = 4;
		if (!ft_strncmp(lower, "unset", ft_strlen(lower)))
			val = 5;
		if (!ft_strncmp(lower, "cd", ft_strlen(lower)))
			val = 1;
		if (!ft_strncmp(lower, "exit", ft_strlen(lower)))
			val = 7;
		to_lower(lower);
		if (!ft_strncmp(lower, "echo", ft_strlen(lower)))
			val = 2;
		if (!ft_strncmp(lower, "pwd", ft_strlen(lower)))
			val = 3;
		if (!ft_strncmp(lower, "env", ft_strlen(lower)))
			val = 6;
		free(lower);
	}
	return (val);
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
