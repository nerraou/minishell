/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dividing_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:22:52 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/12 16:23:23 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	divide_by_last_operator(t_element *f_cmd, t_element *l_cmd,t_opr_logic *opertor)
{
	t_token		*token;
	int			parentheses;

	parentheses = 1;
	opertor->operator = 0;
	opertor->f_cmd = f_cmd;
	opertor->l_cmd = l_cmd;
	opertor->opr_cmd = l_cmd;
	while (opertor->opr_cmd != opertor->f_cmd)
	{
		token = (t_token *)opertor->opr_cmd->content;
		if (token->type == T_R_PARENTH)  // )
			parentheses = 0;
		if (token->type == T_L_PARENTH)  // (
			parentheses = 1;
		if (parentheses)
		{
			if (token->type == T_AND || token->type == T_OR)
			{
				opertor->operator = token->type;
				token->type = -1;
				break ;
			}
		}
		opertor->opr_cmd = opertor->opr_cmd->prev;
	}
}