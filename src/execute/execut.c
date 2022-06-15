/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:07:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/15 12:07:55 by obelkhad         ###   ########.fr       */
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

void	priority_handling(t_element *f_cmd, t_element *l_cmd, char **envp)
{
	t_opr_logic	operators;
	// t_token *token;
	// t_element *elm;
	// elm = f_cmd;
	// while (elm && elm->prev != l_cmd)
	// {
	// 	token = (t_token *)elm->content;
    //     printf("[ %s ][%d]\n",token->value, token->type);
    //     elm = elm->next;
	// }printf("--------------------------\n");

	operators.f_cmd = f_cmd;
	operators.opr_cmd = l_cmd;
	operators.l_cmd = l_cmd;

	check_parentheses(&operators);

	divide_by_last_operator(f_cmd, l_cmd, &operators);

		// token = (t_token *)operators.f_cmd->content;
		// printf("[ %s ]\n",token->value);
		// token = (t_token *)operators.opr_cmd->content;
		// printf("[ %s ]\n",token->value);
		// token = (t_token *)operators.l_cmd->content;
		// printf("[ %s ]\n",token->value);
		// printf("-------------------------2-\n");

	if (operators.opr_cmd == operators.f_cmd)
	{
		// printf("[ if ]\n");
		// token = (t_token *)operators.f_cmd->content;
		// printf("[ %s ]\n",token->value);
		// token = (t_token *)operators.opr_cmd->content;
		// printf("[ %s ]\n",token->value);
		// token = (t_token *)operators.l_cmd->content;
		// printf("[ %s ]\n",token->value);
		// printf("--------------------------\n");
		if (check_parentheses(&operators))
			priority_handling(operators.f_cmd, operators.l_cmd, envp);
		else
			cmd_execut(operators.f_cmd, operators.l_cmd, envp);
	}
	else
	{

		// printf("[ else ]\n");
		// token = (t_token *)operators.f_cmd->content;
		// printf("[ %s ]\n",token->value);
		// token = (t_token *)operators.opr_cmd->content;
		// printf("[ %s ]\n",token->value);
		// token = (t_token *)operators.l_cmd->content;
		// printf("[ %s ]\n",token->value);
		// printf("--------------------------\n");
		priority_handling(operators.f_cmd, operators.opr_cmd->prev, envp);
	}
	if (operators.operator == T_OR && 0) // && cmd not success
	{
		if (operators.parent_l && operators.parent_r)
		{
			operators.opr_cmd = operators.parent_l;
			operators.l_cmd = operators.parent_r;
		}
		else
			operators.opr_cmd = operators.opr_cmd->next;
		priority_handling(operators.opr_cmd->next, operators.l_cmd, envp);
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
		priority_handling(operators.opr_cmd, operators.l_cmd, envp);
	}
}
