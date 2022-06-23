/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dividing_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:22:52 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/23 19:32:22 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	divide_by_last_operator(t_opr_logic *opertor)
{
	t_token		*token;
	int			parentheses;


	parentheses = 0;
	opertor->operator = 0;
	token = (t_token *)opertor->l_cmd->content;
	if (token->type == T_R_PARENTH)
	{
		opertor->parent_r = opertor->l_cmd;
		opertor->l_cmd = opertor->l_cmd->prev;
		token = (t_token *)opertor->l_cmd->content;
		while (token->type != T_L_PARENTH || parentheses)
		{
			if (token->type == T_R_PARENTH)
				parentheses--;
			if (token->type == T_L_PARENTH)
				parentheses++;
			opertor->l_cmd = opertor->l_cmd->prev;
			token = (t_token *)opertor->l_cmd->content;
		}
		opertor->opr_cmd = opertor->l_cmd->prev;
		opertor->parent_l = opertor->l_cmd;
	}
	else
	{
		opertor->parent_r = NULL;
		opertor->parent_l = NULL;
	}
	token = (t_token *)opertor->f_cmd->next->content;
	printf("F-- %s --\n",token->value);
	token = (t_token *)opertor->l_cmd->prev->content;
	printf("L-- %s --\n",token->value);
	token = (t_token *)opertor->opr_cmd->content;
	printf("O-- %s --\n",token->value);
	while (opertor->opr_cmd != opertor->f_cmd)
	{
		// token = (t_token *)opertor->f_cmd->content;
		// printf("F-- %s --\n",token->value);
		// token = (t_token *)opertor->l_cmd->content;
		// printf("L-- %s --\n",token->value);
		token = (t_token *)opertor->opr_cmd->content;
		// printf("O-- %s --\n",token->value);

		if (token->type == T_R_PARENTH)
			parentheses--;
		if (token->type == T_L_PARENTH)
			parentheses++;
		if (!parentheses)
		{
			if (token->type == T_AND || token->type == T_OR)
			{
				opertor->operator = token->type;
				token->type = -1;
				break ;
			}
			printf("LOL\n");
		}
		opertor->opr_cmd = opertor->opr_cmd->prev;
	}
}