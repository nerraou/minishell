/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_r_parenthesis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:46:58 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/27 18:45:14 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_r_parenthesis(t_element *cur_elm)
{
	t_token	*token;

	token = (t_token *)cur_elm->content;
	if (token->type == T_R_PARENTH)
		return (1);
	return (0);
}
