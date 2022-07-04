/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:53:37 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 08:05:01 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	filename_argument_required(t_cmd *cmd)
{
	write(2, "MiniShell: ", ft_strlen("MiniShell: "));
	write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
	write(2, ": filename argument required\n", ft_strlen(": filename argument \
	required\n"));
	write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
	write(2, ": usage: ", ft_strlen(": usage: "));
	write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
	write(2, " filename [arguments]\n", ft_strlen(" filename [arguments]\n"));
	return (4);
}

int	permission_denied(t_cmd *cmd)
{
	write(2, "MiniShell: ", ft_strlen("MiniShell: "));
	write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
	write(2, " :Permission denied\n", ft_strlen(" :Permission denied\n"));
	return (3);
}

int	is_a_directory(t_cmd *cmd)
{
	write(2, "MiniShell: ", ft_strlen("MiniShell: "));
	write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
	write(2, " :is a directory\n", ft_strlen(" :is a directory\n"));
	return (3);
}

int	no_such_file_or_directory(t_cmd *cmd)
{
	write(2, "MiniShell: ", ft_strlen("MiniShell: "));
	write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
	write(2, " :No such file or directory\n", ft_strlen(" \
	:No such file or directory\n"));
	return (0);
}

int	cmd_not_found(t_cmd *cmd)
{
	write(2, "MiniShell: ", ft_strlen("MiniShell: "));
	write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
	write(2, " : command not found\n", ft_strlen(" : command not found\n"));
	return (0);
}
