/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:07:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/12 16:29:20 by obelkhad         ###   ########.fr       */
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
		return (1);
	}
	return (0);
}

void	priority_handling(t_element *f_cmd, t_element *l_cmd, char **envp)
{
	t_opr_logic	operators;

	divide_by_last_operator(f_cmd, l_cmd, &operators);
	if (operators.opr_cmd == operators.f_cmd)
	{
		if (check_parentheses(&operators))
			priority_handling(operators.f_cmd, operators.l_cmd, envp);
		else
			cmd_execut(operators.f_cmd, operators.l_cmd, envp);
	}
	else
		priority_handling(operators.f_cmd, operators.opr_cmd->prev, envp);
	if (operators.operator == T_OR && 0) // && cmd not success
		priority_handling(operators.opr_cmd->next, operators.l_cmd, envp);
	if (operators.operator == T_AND && 1) // && cmd success
		priority_handling(operators.opr_cmd->next, operators.l_cmd, envp);
}
