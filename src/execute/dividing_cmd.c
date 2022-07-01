/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dividing_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:22:52 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/01 11:08:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unclosed_parenthese(t_token *token, int *parentheses)
{
	if (token->type == T_R_PARENTH)
		(*parentheses)--;
	if (token->type == T_L_PARENTH)
		(*parentheses)++;
}

void	skip_parentheses(t_opr_logic *opertor, t_token *token, int parentheses)
{
	t_element	*elm;

	if (token->type == T_R_PARENTH)
	{
		elm = opertor->l_cmd->prev;
		token = (t_token *)elm->content;
		while (token->type != T_L_PARENTH || parentheses)
		{
			unclosed_parenthese(token, &parentheses);
			elm = elm->prev;
			token = (t_token *)elm->content;
		}
		token = (t_token *)elm->prev->content;
		if (token->type == T_AND || token->type == T_OR)
		{
			opertor->parent_r = opertor->l_cmd;
			opertor->l_cmd = elm;
			opertor->parent_l = opertor->l_cmd;
			opertor->opr_cmd = opertor->l_cmd->prev;
		}
	}
}

void	divide_by_last_operator(t_opr_logic *opertor)
{
	t_token		*token;
	int			parentheses;

	parentheses = 0;
	opertor->operator = 0;
	token = (t_token *)opertor->l_cmd->content;
	skip_parentheses(opertor, token, parentheses);
	while (opertor->opr_cmd != opertor->f_cmd)
	{
		token = (t_token *)opertor->opr_cmd->content;
		unclosed_parenthese(token, &parentheses);
		if (!parentheses)
		{
			if (token->type == T_AND || token->type == T_OR)
			{
				opertor->operator = token->type;
				break ;
			}
		}
		opertor->opr_cmd = opertor->opr_cmd->prev;
	}
}
