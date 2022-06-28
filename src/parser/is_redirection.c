/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:40:02 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/27 18:46:24 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_redirection(t_element *cur_elem)
{
	t_token	*token;

	token = (t_token *)cur_elem->content;
	if (token->type == T_LESS || token->type == T_GREAT
		|| token->type == T_DGREAT)
		return (1);
	return (0);
}
