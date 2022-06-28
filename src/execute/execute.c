/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:25:43 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 17:23:12 by obelkhad         ###   ########.fr       */
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
}

void	pipe_handling(t_element	**pipes, t_element	*l_cmd, t_cmd **cmd)
{
	t_token		*token;

	detect_pipe(pipes, l_cmd);
	token = (t_token *)(*pipes)->content;
	creat_pipe(cmd, token);
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
	int			child;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
	{
		list_del(&env_list, free);
		exit (1);
	}
	init_cmd(cmd);
	dollar_handling(f_cmd, l_cmd, list_to_array(env_list));
	join_pieces(f_cmd, l_cmd);
	pipes = f_cmd;
	while (pipes && pipes->prev != l_cmd)
	{
		pipe_handling(&pipes, l_cmd, &cmd);
		child = fork_proc(f_cmd, pipes, env_list, &cmd);
		last_child(cmd, child);
		move_forward(cmd, &pipes, &f_cmd);
	}
	while (waitpid(-1, NULL, 0) > 0)
		;
	dup2(in, STDIN_FILENO);
}
