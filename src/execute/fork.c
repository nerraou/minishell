/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:24:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 17:54:05 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_in(t_cmd *cmd, t_element **l_cmd)
{
	t_token	*token;

	token = (t_token *)(*l_cmd)->content;
	if (token->type == T_PIPE)
	{
		token->type = -1;
		*l_cmd = (*l_cmd)->prev;
		close(cmd->pipes[READ_END]);
		dup2(cmd->pipes[WRITE_END], STDOUT_FILENO);
		close(cmd->pipes[WRITE_END]);
	}
}

void	free_cmd(t_cmd **cmd)
{
	free((*cmd)->cmd);
	free((*cmd)->cmd_name);
	free_2_arr((*cmd)->args);
	free (*cmd);
}

void	in_out(t_element *f_cmd, t_element **l_cmd, t_cmd **cmd)
{
	pipe_in(*cmd, l_cmd);
	get_io(f_cmd, *l_cmd);
}

int	fork_proc(t_element *f_cmd, t_element *l_cmd, t_list *env_, t_cmd **cmd)
{
	int			child;
	t_opr_logic	operators;
	int			built;

	child = fork();
	if (child == 0)
	{
		in_out(f_cmd, &l_cmd, cmd);
		operators.f_cmd = f_cmd;
		operators.l_cmd = l_cmd;
		check_parentheses(&operators);
		executable_cmd(operators.f_cmd, list_to_array(env_), *cmd);
		wildcard_expand(f_cmd, l_cmd);
		prepear_execve_args(operators.f_cmd, operators.l_cmd, *cmd);
		built = is_builtin((*cmd)->cmd_name);
		if (!built)
			execve((*cmd)->args[0], (*cmd)->args, list_to_array(env_));
		else
		{
			exe_builtin(built, *cmd, env_);
			exit(g_vars.exit_code);
			free_cmd(cmd);
		}
	}
	return (child);
}
