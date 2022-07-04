/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:46:37 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 11:35:36 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	retrieve_old_cmds(char *file)
{
	int		fd;
	char	*old_cmd;

	fd = open(file, O_RDONLY);
	old_cmd = get_next_line(fd);
	while (old_cmd)
	{
		add_history(ft_substr(old_cmd, 0, ft_strlen(old_cmd) - 1));
		free(old_cmd);
		old_cmd = get_next_line(fd);
	}
	close(fd);
}

void	history(char *cmd, char **envp)
{
	int		fd;
	char	*file;

	file = ft_strjoin(get_env_value("HOME=", envp), "/.mini_sh_history");
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
}
