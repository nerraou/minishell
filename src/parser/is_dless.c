/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dless.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:51:51 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/27 18:43:41 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_dless(t_element *cur_elem)
{
	t_token	*token;

	token = (t_token *)cur_elem->content;
	if (token->type == T_DLESS)
		return (1);
	return (0);
}
