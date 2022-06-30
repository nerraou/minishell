/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:25:43 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/30 17:18:12 by obelkhad         ###   ########.fr       */
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

	if (cmd->next_is_pipes == 0)
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

int	check_builtin(t_element *f_cmd, t_element *l_cmd, t_cmd *cmd, t_list *env_)
{
	(void)f_cmd;
	(void)l_cmd;
	t_element	*elm;
	t_token		*token;
	t_opr_logic	operators;
	int			built;

	elm = f_cmd;
	token = (t_token *)elm->content;
	if (token->type == T_GREAT || token->type == T_LESS)
	{
		if (elm->next)
			elm = elm->next;
		else
			return (0);
		if (elm->next)
			elm = elm->next;
		else
			return (0);
	}
	// in_out(f_cmd, &l_cmd, cmd);
	// 	operators.f_cmd = f_cmd;
	// 	operators.l_cmd = l_cmd;
	// 	check_parentheses(&operators);
	// 	executable_cmd(operators.f_cmd, list_to_array(env_), *cmd);
	// 	wildcard_expand(f_cmd, l_cmd);
	// 	prepear_execve_args(operators.f_cmd, operators.l_cmd, *cmd);

	if (cmd->id == 0 && cmd->next_is_pipes == 0)
	{
		get_io(f_cmd, l_cmd);
		executable_cmd(operators.f_cmd, list_to_array(env_), cmd);
		built = is_builtin(cmd->cmd_name);
		
		printf("LOL\n");
	}
	return (0);
}

void	execute(t_element *f_cmd, t_element *l_cmd, t_list *env_list, int in)
{
	t_element	*pipes;
	t_cmd		*cmd;

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
		if (check_builtin(f_cmd, l_cmd, cmd, env_list) == -1)
			fork_proc(f_cmd, pipes, env_list, &cmd);
		last_child(cmd);
		move_forward(cmd, &pipes, &f_cmd);
	}
	while (waitpid(-1, NULL, 0) > 0)
		;
	dup2(in, STDIN_FILENO);
}
