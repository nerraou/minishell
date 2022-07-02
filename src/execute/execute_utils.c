/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:32:27 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/02 21:55:38 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_2_arr(char **env_arr)
{
	int	i;

	i = 0;
	while (env_arr[i])
	{
		free (env_arr[i]);
		i++;
	}
	free (env_arr);
}

void	init_cmd(t_cmd *cmd)
{
	cmd->id = 0;
	cmd->cmd = NULL;
	cmd->cmd_name = NULL;
	cmd->args = NULL;
	cmd->next_is_pipes = 0;
	cmd->built_exit = 10;
	cmd->built = 0;
	cmd->num_of_args = 0;
	cmd->pid = 0;
	cmd->executable = 0;
}

void	get_exit_code(int status)
{
	if (WIFEXITED(status))
		g_vars.exit_code = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
		g_vars.exit_code = WTERMSIG(status) + 128;
}


void	creat_pipe(t_cmd **cmd, t_token *token)
{
	if (token->type == T_PIPE)
	{
		(*cmd)->next_is_pipes = 1;
		if (pipe((*cmd)->pipes) == -1)
			perror("minish: pipe");
	}
}

void	detect_pipe(t_element **pipes, t_element *l_cmd)
{
	t_token		*token;

	token = (t_token *)(*pipes)->content;
	while (token->type != T_PIPE && (*pipes) != l_cmd)
	{
		(*pipes) = (*pipes)->next;
		token = (t_token *)(*pipes)->content;
	}
}
