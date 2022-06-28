/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:32:27 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 17:11:22 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_out(t_cmd *cmd)
{
	cmd->next_is_pipes = 0;
	close(cmd->pipes[WRITE_END]);
	dup2(cmd->pipes[READ_END], STDIN_FILENO);
	close(cmd->pipes[READ_END]);
}

void	get_exit_code(int *status)
{
	if (WIFEXITED(*status))
		g_vars.exit_code = WEXITSTATUS(*status);
	else if (WIFSIGNALED(*status))
		g_vars.exit_code = WTERMSIG(*status) + 128;
}

void	last_child(t_cmd *cmd, int child)
{
	int	status;

	if (cmd->next_is_pipes == 0)
	{
		waitpid(child, &status, 0);
		close(STDIN_FILENO);
		get_exit_code(&status);
	}
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
