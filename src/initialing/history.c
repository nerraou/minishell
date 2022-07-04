/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:46:37 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 19:26:32 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	retrieve_old_cmds(char *file)
{
	int		fd;
	char	*old_cmd;
	char	*holder;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	old_cmd = get_next_line(fd);
	while (old_cmd)
	{
		holder = ft_substr(old_cmd, 0, ft_strlen(old_cmd) - 1);
		add_history(holder);
		free(old_cmd);
		free(holder);
		old_cmd = get_next_line(fd);
	}
	close(fd);
}

void	history(char *cmd, char **envp)
{
	int		fd;
	char	*file;
	char	*env;

	env = get_env_value("HOME=", envp);
	file = ft_strjoin(env, "/.mini_sh_history");
	fd = open(file, O_APPEND | O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd < 0)
		return ;
	if (cmd)
	{
		write(fd, cmd, ft_strlen(cmd));
		add_history(cmd);
		write(fd, "\n", 1);
	}
	close(fd);
	retrieve_old_cmds(file);
	free(file);
	free(env);
}
