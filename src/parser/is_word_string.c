/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:27:36 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/01 18:40:44 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_word_string(t_element *cur_elem)
{
	t_token	*token;

	token = (t_token *)cur_elem->content;
	if (token->type == T_S_STRING || token->type == T_D_STRING
		|| token->type == T_WORD)
		return (1);
	return (0);
}
