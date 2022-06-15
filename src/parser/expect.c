/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:53:44 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/15 12:23:53 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int expect(t_element *cur_elem, t_element *next_elem)
{
	if (is_separator(cur_elem) && separator_expect(next_elem))
		return FT_FAILURE;
	else if (is_redirection(cur_elem))
	{
		if (symbol_expect(next_elem) == FT_SUCCESS)
			return FT_SUCCESS;
		return FT_FAILURE;
	}
	else if (is_dless(cur_elem))
	{
		if (dless_expect(next_elem) == FT_SUCCESS)
			return FT_SUCCESS;
		return FT_FAILURE;
	}
	return FT_SUCCESS;
}
