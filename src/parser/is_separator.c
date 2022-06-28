/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:35:10 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/27 18:46:49 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_separator(t_element *cur_elem)
{
	t_token	*token;

	token = (t_token *)cur_elem->content;
	if (token->type == T_PIPE || token->type == T_OR
		|| token->type == T_AND)
		return (1);
	return (0);
}
