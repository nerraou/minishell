/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:28:51 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/23 18:44:53 by obelkhad         ###   ########.fr       */
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

int	check_access(t_cmd *cmd, char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		cmd->cmd = ft_strjoin(path[i], cmd->cmd_name);
		if (!access(cmd->cmd, X_OK))
			break ;
		i++;
	}
	if (path[i])
		cmd->executable = 1;
	else
	{
		cmd->executable = 0;
		write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
		write(2, " :command not found\n", ft_strlen(" :command not found\n"));
	}
	return (cmd->executable);
}

int	executable_cmd(t_element *f_cmd, char **envp, t_cmd *cmd)
{
	t_element	*elm;
	t_token		*token;
	char		**path;

	elm = f_cmd;
	cmd->executable = 2;
	token = (t_token *)elm->content;
	while (elm && token->type == -1)
	{
		elm = elm->next;
		if (elm)
			token = (t_token *)elm->content;
	}
	if (elm)
	{
		token->type = 100;
		cmd->cmd_name = ft_strdup(token->value);
		path = get_path_from_env(envp);
		if (!path)
		{
			/*free*/
			exit (1);
		}
		cmd->executable = check_access(cmd, path);
	}
	return (cmd->executable);
}