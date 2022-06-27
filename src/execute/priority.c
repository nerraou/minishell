/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:07:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/23 18:30:22 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_parentheses(t_opr_logic *operators)
{
	t_token		*tokenr;
	t_token		*tokenl;
	t_element	*first;
	t_element	*last;
	t_element	*r_prnth;

	first = operators->f_cmd;
	r_prnth = operators->f_cmd;
	last = operators->l_cmd;
	tokenr = (t_token *)r_prnth->content;
	int parentheses = 0;
	while (r_prnth && r_prnth != last)
	{
		r_prnth = r_prnth->next;
		tokenr = (t_token *)r_prnth->content;
		if (tokenr->type == T_R_PARENTH && !parentheses)
			break ;
		if (tokenr->type == T_L_PARENTH)
			parentheses++;
		if (tokenr->type == T_R_PARENTH)
			parentheses--;
	}
	tokenl = (t_token *)first->content;
	tokenr = (t_token *)last->content;
	if(tokenl->type == T_L_PARENTH && tokenr->type == T_R_PARENTH && r_prnth == last)
	{
		operators->f_cmd = operators->f_cmd->next;
		operators->l_cmd = operators->l_cmd->prev;
		operators->opr_cmd = operators->l_cmd;
		return (check_parentheses(operators), 1);
	}
	return (0);
}

void	priority(t_element *f_cmd, t_element *l_cmd, char **envp, int in)
{
	t_opr_logic	operators;

	operators.f_cmd = f_cmd;
	operators.opr_cmd = l_cmd;
	operators.l_cmd = l_cmd;
	operators.parent_l = NULL;
	operators.parent_r = NULL;
	check_parentheses(&operators);
	divide_by_last_operator(&operators);
	if (operators.opr_cmd == operators.f_cmd)
	{
		if (check_parentheses(&operators))
			priority(operators.f_cmd, operators.l_cmd, envp, in);
		else
			execute(operators.f_cmd, operators.l_cmd, envp, in);
	}
	else
		priority(operators.f_cmd, operators.opr_cmd->prev, envp, in);
	if (operators.operator == T_OR && global_vars.exit_code)
	{
		if (operators.parent_l && operators.parent_r)
		{
			operators.opr_cmd = operators.parent_l;
			operators.l_cmd = operators.parent_r;
		}
		else
			operators.opr_cmd = operators.opr_cmd->next;
		priority(operators.opr_cmd, operators.l_cmd, envp, in);
	}
	if (operators.operator == T_AND && !global_vars.exit_code)
	{
		if (operators.parent_l && operators.parent_r)
		{
			operators.opr_cmd = operators.parent_l;
			operators.l_cmd = operators.parent_r;
		}
		else
			operators.opr_cmd = operators.opr_cmd->next;
		priority(operators.opr_cmd, operators.l_cmd, envp, in);
	}
}
