/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:07:47 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 18:08:42 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_slash(char *cmd)
{
	int	i;

	i = 0;
	while (cmd && cmd[i] && cmd[i] != '/')
		i++;
	if (cmd && cmd[i])
		return (i);
	return (-1);
}

int	chack_access(t_cmd **cmd, char **envp)
{
	char	**path;
	int		i;

	i = -1;
	path = get_path_from_env(envp);
	if (path)
	{
		while (path[++i])
		{
			if ((*cmd)->cmd)
				free ((*cmd)->cmd);
			(*cmd)->cmd = ft_strjoin(path[i], (*cmd)->cmd_name);
			if (!access((*cmd)->cmd, X_OK))
				break ;
		}
		if (path[i])
			return (free_2_arr(path), 1);
		else
			return (free_2_arr(path), cmd_not_found(*cmd));
	}
	else
		return (cmd_not_found(*cmd));
}

int	check_slash(t_cmd **cmd, char **envp)
{
	int		i;
	char	*holder;

	i = ft_strlen((*cmd)->cmd_name) - 1;
	while (i >= 0 && (*cmd)->cmd_name[i] != '/')
		i--;
	if (i == -1)
		return (chack_access(cmd, envp));
	holder = ft_substr((*cmd)->cmd_name, i + 1, \
	ft_strlen((*cmd)->cmd_name) - i + 1);
	free((*cmd)->cmd_name);
	(*cmd)->cmd_name = ft_strdup(holder);
	free(holder);
	return (1);
}
