/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rparenthesis_expect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:09:04 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 09:49:04 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	rparenthesis_expect(t_element *next_elm)
{
	if (next_elm == NULL)
		return (FT_SUCCESS);
	if ((!is_separator(next_elm) && !is_r_parenthesis(next_elm)))
	{
		print_syntax_error(next_elm);
		return (FT_FAILURE);
	}
	return (FT_SUCCESS);
}
