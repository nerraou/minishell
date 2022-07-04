/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:25:43 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 08:11:50 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_handling(t_element	**pipes, t_element	*l_cmd, t_cmd **cmd)
{
	t_token		*token;

	detect_pipe(pipes, l_cmd);
	token = (t_token *)(*pipes)->content;
	creat_pipe(cmd, token);
}

void	last_child(t_cmd *cmd)
{
	int	status;

	if (cmd->next_is_pipes == 0 && cmd->pid != -2)
	{
		waitpid(cmd->pid, &status, 0);
		close(STDIN_FILENO);
		get_exit_code(status);
	}
}

void	pipe_out(t_cmd *cmd)
{
	cmd->next_is_pipes = 0;
	close(cmd->pipes[WRITE_END]);
	dup2(cmd->pipes[READ_END], STDIN_FILENO);
	close(cmd->pipes[READ_END]);
}

void	move_forward(t_cmd *cmd, t_element **pipes, t_element **f_cmd)
{
	if (cmd->next_is_pipes)
		pipe_out(cmd);
	cmd->id++;
	*pipes = (*pipes)->next;
	*f_cmd = *pipes;
}

void	execute(t_element *f_cmd, t_element *l_cmd, t_list *env_list, int in)
{
	t_element	*pipes;
	t_cmd		*cmd;
	int			out;

	out = dup(STDOUT_FILENO);
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
	{
		list_del(&env_list, free);
		exit (1);
	}
	prepear_cmd(f_cmd, l_cmd, env_list, cmd);
	pipes = f_cmd;
	while (pipes && pipes->prev != l_cmd)
	{
		pipe_handling(&pipes, l_cmd, &cmd);
		fork_proc(f_cmd, pipes, env_list, &cmd);
		last_child(cmd);
		move_forward(cmd, &pipes, &f_cmd);
	}
	while (waitpid(-1, NULL, 0) > 0)
		;
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
}
