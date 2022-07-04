/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:28:51 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 11:31:53 by obelkhad         ###   ########.fr       */
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

int	check_stat(t_cmd **cmd, struct stat statbuf, char **envp)
{
	if (!ft_strcmp((*cmd)->cmd_name, "."))
		return (filename_argument_required((*cmd)));
	if (!ft_strcmp((*cmd)->cmd_name, ".."))
		return (cmd_not_found((*cmd)));
	else if ((statbuf.st_mode & S_IFMT) == S_IFDIR)
		return (is_a_directory((*cmd)));
	else if ((!(statbuf.st_mode & S_IXUSR) || !(statbuf.st_mode & S_IRUSR)) && \
	is_slash((*cmd)->cmd_name) != -1)
		return (permission_denied((*cmd)));
	return (check_slash(cmd, envp));
}

int	check_stat_path(t_cmd *cmd, char **envp)
{
	struct stat	statbuf;

	if (!stat(ft_strdup(cmd->cmd_name), &statbuf))
		return (check_stat(&cmd, statbuf, envp));
	else if (is_slash(cmd->cmd_name) != -1)
		return (no_such_file_or_directory(cmd));
	else
		return (chack_access(cmd, envp));
}

void	executable(t_element *f_cmd, t_element *l_cmd, char **envp, t_cmd *cmd)
{
	t_element	*elm;
	t_token		*token;

	elm = f_cmd;
	cmd->executable = 2;
	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		if (check_cmd(token->type))
			elm = elm->next;
		else
			break ;
	}
	if (elm && elm->prev != l_cmd)
	{
		token->type = 100;
		cmd->cmd_name = ft_strdup(token->value);
		cmd->cmd = ft_strdup(token->value);
		if (!is_builtin(cmd->cmd_name))
			cmd->executable = check_stat_path(cmd, envp);
		else
			cmd->executable = 1;
	}
	free_2_arr (envp);
}
