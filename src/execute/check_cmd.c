/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:28:51 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/03 20:18:55 by obelkhad         ###   ########.fr       */
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

int	check_slash(t_cmd **cmd)
{
	int		i;
	char	*holder;

	i = ft_strlen((*cmd)->cmd_name) - 1;
	while (i >= 0 && (*cmd)->cmd_name[i] != '/' && (*cmd)->cmd_name[i] != '.')
		i--;
	if (i == -1)
		return (cmd_not_found(*cmd));
	if (i < (int)ft_strlen((*cmd)->cmd_name))
	{
		holder = ft_substr((*cmd)->cmd_name, i + 1, \
		ft_strlen((*cmd)->cmd_name) - i + 1);
		free((*cmd)->cmd_name);
		(*cmd)->cmd_name = ft_strdup(holder);
		free(holder);
	}
	return (1);
}

void	chech_stat(t_cmd *cmd)
{
	struct stat	statbuf;

	stat(ft_strdup(cmd->cmd_name), &statbuf);
	// if (stat(ft_strdup(cmd->cmd_name), &statbuf))
	// {
	// }
	if ((statbuf.st_mode & S_IFMT) == S_IFDIR)
		return (is_a_directory(cmd));
	if (!(statbuf.st_mode & S_IXUSR) || !(statbuf.st_mode & S_IRUSR))
		return (permission_denied(cmd));
}

int	check_access(t_cmd *cmd, char **path)
{
	int	i;

	i = 0;
	check_stat(cmd);
	if (access(cmd->cmd_name, X_OK))
	{
		if (path)
		{
			while (path[i])
			{
				if (cmd->cmd)
					free (cmd->cmd);
				cmd->cmd = ft_strjoin(path[i], cmd->cmd_name);
				if (!access(cmd->cmd, X_OK))
					break ;
				i++;
			}
			if (path[i])
				return (free_2_arr(path), 1);
			else
			{
				if (cmd->cmd_name[0] == '/' || cmd->cmd_name[0] == '.')
					return (no_such_file_or_directory(cmd));
				return (cmd_not_found(cmd));
			}
		}
		else
			return (cmd_not_found(cmd));
	}
	else
	{

		return (1);
		// return (check_slash(&cmd));
	}
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
		cmd->cmd = ft_strdup(token->value);
		if (!is_builtin(cmd->cmd_name))
		{
			path = get_path_from_env(envp);
			cmd->executable = check_access(cmd, path);
		}
		else
			cmd->executable = 1;
	}
	free_2_arr (envp);
}
