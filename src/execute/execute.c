/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:25:43 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/23 18:57:49 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd(t_cmd *cmd)
{
	cmd->id = 0;
	cmd->cmd = NULL;
	cmd->cmd_name = NULL;
	cmd->args = NULL;
	cmd->next_is_pipes = 0;
}

void	execute(t_element *f_cmd, t_element *l_cmd, char **envp, int in)
{
	t_element	*pipes;
	t_token		*token;
	t_cmd		*cmd;
	int			child;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
	{
		/*free*/
		/*exit (1)*/
	}
	init_cmd(cmd);
	expanding(f_cmd, l_cmd, envp);
	join_pieces(f_cmd, l_cmd);
	pipes = f_cmd;
	while (pipes && pipes->prev != l_cmd)
	{
		token = (t_token *)pipes->content;
		while (token->type != T_PIPE && pipes != l_cmd)
		{
			pipes = pipes->next;
			token = (t_token *)pipes->content;
		}
		if (token->type == T_PIPE)
		{
			cmd->next_is_pipes = 1;
			if (pipe(cmd->pipes) == -1)
				perror("minish: pipe");
		}
		child = fork_proccesses(f_cmd, pipes, envp, cmd);
		if (!cmd->next_is_pipes)
		{
			waitpid(child, NULL, 0);
			close(STDIN_FILENO);
		}
		if (cmd->next_is_pipes)
		{
			cmd->next_is_pipes = 0;
			close(cmd->pipes[WRITE_END]);
			dup2(cmd->pipes[READ_END], STDIN_FILENO);
			close(cmd->pipes[READ_END]);
		}
		cmd->id++;
		pipes = pipes->next;
		f_cmd = pipes;
	}
	while (waitpid(-1, NULL, 0) > 0);
	dup2(in, STDIN_FILENO);
}