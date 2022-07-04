/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:24:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 11:30:34 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_in(t_cmd *cmd, t_element **l_cmd)
{
	t_token	*token;

	token = (t_token *)(*l_cmd)->content;
	if (token->type == T_PIPE)
	{
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
	if ((*cmd)->args)
		free_2_arr((*cmd)->args);
	free (*cmd);
}

int	in_out(t_element *f_cmd, t_element **l_cmd, t_cmd **cmd)
{
	pipe_in(*cmd, l_cmd);
	return (get_io(f_cmd, *l_cmd));
}

void	update_type(t_element *f_cmd, t_element *l_cmd)
{
	t_element	*elm;
	t_token		*token;
	t_token		*file;

	elm = f_cmd;
	token = (t_token *)elm->content;
	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		if (elm->next)
			file = (t_token *)elm->next->content;
		if (token->type == T_GREAT || token->type == T_LESS || \
		token->type == T_DGREAT)
			file->type = T_FILE;
		if (token->type == T_DLESS)
			file->type = T_LIM;
		elm = elm->next;
	}
}

void	fork_proc(t_element *f_cmd, t_element *l_cmd, t_list *env_, t_cmd **cmd)
{
	t_opr_logic	operators;

	operators.f_cmd = f_cmd;
	operators.l_cmd = l_cmd;
	check_parentheses(&operators);
	update_type(operators.f_cmd, operators.l_cmd);
	executable(operators.f_cmd, operators.l_cmd, list_to_array(env_), *cmd);
	wildcard_expand(f_cmd, l_cmd);
	prepear_execve_args(operators.f_cmd, operators.l_cmd, *cmd);
	(*cmd)->built = is_builtin((*cmd)->cmd_name);
	if ((*cmd)->id == 0 && (*cmd)->next_is_pipes == 0 && (*cmd)->built)
	{
		get_io(f_cmd, l_cmd);
		g_vars.exit_code = exe_builtin((*cmd)->built, *cmd, env_);
		free_cmd(cmd);
	}
	else
		forking(f_cmd, l_cmd, env_, cmd);
}
