/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:28:51 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 16:09:51 by obelkhad         ###   ########.fr       */
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

void	check_slash(char **name)
{
	int		i;
	char	*holder;

	i = ft_strlen(*name);
	while ((*name)[i - 1] != '/' && (*name)[i - 1] != '.')
		i--;
	holder = ft_substr(*name, i, ft_strlen(*name) - i + 1);
	free(*name);
	*name = holder;
}

void	replace_cat(t_cmd *cmd)
{
	cmd->executable = 0;
	write(2, "MiniShell: ", ft_strlen("MiniShell: "));
	write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
	write(2, " :command not found\n", ft_strlen(" :command not found\n"));
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
			cmd->cmd = cmd->cmd_name;
			check_slash(&cmd->cmd_name);
			break ;
		}
		i++;
	}
	if (path[i])
		cmd->executable = 1;
	else
		replace_cat(cmd);
	return (cmd->executable);
}

void	executable_cmd(t_element *f_cmd, char **envp, t_cmd *cmd)
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
			exit (1);
		cmd->executable = check_access(cmd, path);
	}
	free_2_arr (envp);
}
