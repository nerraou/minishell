/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:28:51 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/01 20:05:03 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path_from_env(char *envp[])
{
	char	**path;
	char	*path_line;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (0);
	path_line = (char *)malloc(sizeof(char) * (ft_strlen(envp[i]) + 4));
	ft_strlcpy(path_line, envp[i] + 5, ft_strlen(envp[i]) - 4);
	path = ft_split(path_line, ':');
	free (path_line);
	if (!path)
		return (0);
	i = 0;
	while (path[i])
	{
		path_line = ft_strdup(path[i]);
		free (path[i]);
		path[i] = ft_strjoin(path_line, "/");
		free (path_line);
		i++;
	}
	return (path);
}

void	check_slash(t_cmd **cmd)
{
	int		i;
	char	*holder;

	i = ft_strlen((*cmd)->cmd_name) - 1;
	while (i >= 0 && (*cmd)->cmd_name[i] != '/' && (*cmd)->cmd_name[i] != '.')
		i--;
	if (i == (int)ft_strlen((*cmd)->cmd_name) - 1)
	{
		(*cmd)->executable = 3;
		write(2, "MiniShell: ", ft_strlen("MiniShell: "));
		write(2, (*cmd)->cmd_name, ft_strlen((*cmd)->cmd_name));
		write(2, " :is a directory\n", ft_strlen(" :is a directory\n"));
	}
	else
	{
		holder = ft_substr((*cmd)->cmd_name ,i , ft_strlen((*cmd)->cmd_name) - i + 1);
		free((*cmd)->cmd_name);
		(*cmd)->cmd_name = ft_strdup(holder);
		free(holder);
	}
}

void	cmd_not_found(t_cmd *cmd)
{
	if (!is_builtin(cmd->cmd_name))
	{
		cmd->executable = 0;
		write(2, "MiniShell: ", ft_strlen("MiniShell: "));
		write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
		write(2, " :command not found\n", ft_strlen(" :command not found\n"));
	}
	else
		cmd->executable = 1;
}

int	check_access(t_cmd *cmd, char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (access(cmd->cmd_name, X_OK))
		{
			cmd->cmd = ft_strjoin(path[i], cmd->cmd_name);
			if (!access(cmd->cmd, X_OK))
				break ;
		}
		else
		{
			cmd->cmd = ft_strdup(cmd->cmd_name);
			check_slash(&cmd);
			break ;
		}
		i++;
	}
	if (path[i] && cmd->executable != 3)
		cmd->executable = 1;
	else if (cmd->executable != 3)
		cmd_not_found(cmd);
	return (cmd->executable);
}

void	executable_cmd(t_element *f_cmd, t_element *l_cmd, char **envp, t_cmd *cmd)
{
	t_element	*elm;
	t_token		*token;
	char		**path;

	elm = f_cmd;
	cmd->executable = 2;
	token = (t_token *)elm->content;
	while (elm && elm->prev != l_cmd && check_cmd(token->type))
	{
		elm = elm->next;
		if (elm)
			token = (t_token *)elm->content;
	}
	if (elm && elm->prev != l_cmd)
	{
		token->type = 100;
		cmd->cmd_name = ft_strdup(token->value);
		path = get_path_from_env(envp);
		if (!path)
			exit (1);
		cmd->executable = check_access(cmd, path);
	}
	free_2_arr (envp);
}
