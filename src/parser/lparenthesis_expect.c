/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lparenthesis_expect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:49:10 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/27 18:48:19 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	lparenthesis_expect(t_element *next_elm)
{
	if (next_elm == NULL
		|| (!is_word_string(next_elm) && !(is_l_parenthesis(next_elm))))
	{
		print_syntax_error(next_elm);
		return (FT_FAILURE);
	}
	return (FT_SUCCESS);
}
