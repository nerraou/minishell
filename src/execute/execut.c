/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:07:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/18 17:08:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_parentheses(t_opr_logic *operators)
{
	t_token		*tokenr;
	t_token		*tokenl;
	t_element	*first;
	t_element	*last;

	first = operators->f_cmd;
	last = operators->l_cmd;

	tokenl = (t_token *)first->content;
	tokenr = (t_token *)last->content;
	if(tokenl->type == T_L_PARENTH && tokenr->type == T_R_PARENTH)
	{
		operators->f_cmd = operators->f_cmd->next;
		operators->l_cmd = operators->l_cmd->prev;
		operators->opr_cmd = operators->l_cmd;
		return (1);
	}
	return (0);
}

void	priority_handling(t_element *f_cmd, t_element *l_cmd, char **envp, t_list *heredoc_list)
{
	t_opr_logic	operators;

	operators.f_cmd = f_cmd;
	operators.opr_cmd = l_cmd;
	operators.l_cmd = l_cmd;
	check_parentheses(&operators);
	divide_by_last_operator(&operators);
	if (operators.opr_cmd == operators.f_cmd)
	{
		if (check_parentheses(&operators))
			priority_handling(operators.f_cmd, operators.l_cmd, envp, heredoc_list);
		else
			cmd_execut(operators.f_cmd, operators.l_cmd, envp, heredoc_list);
	}
	else
		priority_handling(operators.f_cmd, operators.opr_cmd->prev, envp, heredoc_list);
	if (operators.operator == T_OR && 0) // && cmd not success
	{
		if (operators.parent_l && operators.parent_r)
		{
			operators.opr_cmd = operators.parent_l;
			operators.l_cmd = operators.parent_r;
		}
		else
			operators.opr_cmd = operators.opr_cmd->next;
		priority_handling(operators.opr_cmd, operators.l_cmd, envp, heredoc_list);
	}
	if (operators.operator == T_AND && 1) // && cmd success
	{
		if (operators.parent_l && operators.parent_r)
		{
			operators.opr_cmd = operators.parent_l;
			operators.l_cmd = operators.parent_r;
		}
		else
			operators.opr_cmd = operators.opr_cmd->next;
		priority_handling(operators.opr_cmd, operators.l_cmd, envp, heredoc_list);
	}
}
