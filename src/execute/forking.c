/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:07:54 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 11:32:20 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	forking(t_element *f_cmd, t_element *l_cmd, t_list *env_, t_cmd **cmd)
{
	(*cmd)->pid = fork();
	if ((*cmd)->pid == 0)
	{
		if (in_out(f_cmd, &l_cmd, cmd))
			exit (1);
		if ((*cmd)->executable == 0)
			exit (127);
		if ((*cmd)->executable == 2)
			exit (0);
		if ((*cmd)->executable == 3)
			exit (126);
		if ((*cmd)->executable == 4)
			exit (2);
		if (!(*cmd)->built)
		{
			execve((*cmd)->args[0], (*cmd)->args, list_to_array(env_));
			exit(0);
		}
		else
		{
			g_vars.exit_code = exe_builtin((*cmd)->built, *cmd, env_);
			free_cmd(cmd);
			exit(g_vars.exit_code);
		}
	}
}
