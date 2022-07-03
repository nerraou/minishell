/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:53:37 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/03 20:17:58 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	permission_denied(t_cmd *cmd)
{

	write(2, "MiniShell: ", ft_strlen("MiniShell: "));
	write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
	write(2, " :Permission denied\n", ft_strlen(" :Permission denied\n"));
	return (4);
}

int	is_a_directory(t_cmd *cmd)
{

	write(2, "MiniShell: ", ft_strlen("MiniShell: "));
	write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
	write(2, " :is a directory\n", ft_strlen(" :is a directory\n"));
	return (4);
}

int	no_such_file_or_directory(t_cmd *cmd)
{
	if (cmd->cmd_name[0] != 0)
	{
		write(2, "MiniShell: ", ft_strlen("MiniShell: "));
		write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
		write(2, " :No such file or directory\n", ft_strlen(" \
		:No such file or directory\n"));
		return (0);
	}
	else
		return (1);
}

int	cmd_not_found(t_cmd *cmd)
{
	if (cmd->cmd_name[0] != 0)
	{
		write(2, "MiniShell: ", ft_strlen("MiniShell: "));
		write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
		write(2, " : command not found\n", ft_strlen(" : command not found\n"));
		return (0);
	}
	else
		return (1);
}
