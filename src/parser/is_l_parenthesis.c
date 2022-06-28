/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_l_parenthesis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:32:34 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/27 18:43:56 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_l_parenthesis(t_element *cur_elm)
{
	t_token	*token;

	token = (t_token *)cur_elm->content;
	if (token->type == T_L_PARENTH)
		return (1);
	return (0);
}
