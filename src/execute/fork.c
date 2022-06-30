/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:24:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/30 20:17:46 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_in(t_cmd *cmd, t_element **l_cmd)
{
	t_token	*token;

	token = (t_token *)(*l_cmd)->content;
	if (token->type == T_PIPE)
	{
		// token->type = -1;
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
		if (token->type == T_GREAT || token->type == T_LESS)
		{
			if (elm->next)
			{
				file = (t_token *)elm->next->content;
				file->type = T_FILE;
			}
		}
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
	executable_cmd(operators.f_cmd, list_to_array(env_), *cmd);
	wildcard_expand(f_cmd, l_cmd);
	// t_element *elm;
	// t_token *tok;
	// elm = f_cmd;
	// while (elm && elm->prev != l_cmd)
	// {
	// 	tok = (t_token*)elm->content;
	// 	printf("{%s}{%d}{%d}\n",tok->value,tok->type,tok->to_join);
	// 	elm = elm->next;
	// }
	// printf("{-------------}\n");
	prepear_execve_args(operators.f_cmd, operators.l_cmd, *cmd);
	(*cmd)->built = is_builtin((*cmd)->cmd_name);
	// printf("__cmd = %s\n",(*cmd)->cmd);
	// printf("__name = %s\n",(*cmd)->cmd_name);
	// printf("__exe = %d\n",(*cmd)->executable);
	// printf("__n_pipe = %d\n",(*cmd)->next_is_pipes);
	// printf("__id = %d\n",(*cmd)->id);
	// printf("__built = %d\n",(*cmd)->built);
	// int i = 0;
	// while ((*cmd)->args[i])
	// {
	// 	printf("___rg = %s\n",(*cmd)->args[i]);
	// 	i++;
	// }
	if ((*cmd)->id == 0 && (*cmd)->next_is_pipes == 0 && (*cmd)->built)
	{
		get_io(f_cmd, l_cmd);
		exe_builtin((*cmd)->built, *cmd, env_);
		free_cmd(cmd);
	}
	else
	{
		(*cmd)->pid = fork();
		if ((*cmd)->pid == 0)
		{
			if((*cmd)->executable == 0)
				exit (127);
			in_out(f_cmd, &l_cmd, cmd);
			(*cmd)->built = is_builtin((*cmd)->cmd_name);
			if (!(*cmd)->built)
				execve((*cmd)->args[0], (*cmd)->args, list_to_array(env_));
			else
			{
				exe_builtin((*cmd)->built, *cmd, env_);
				free_cmd(cmd);
				exit(g_vars.exit_code);
			}
		}
	}
}