/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:53:44 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/27 16:26:03 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	expect(t_element *cur_elem, t_element *next_elem)
{
	int	check;

	check = FT_SUCCESS;
	if (is_separator(cur_elem) && separator_expect(next_elem))
		return (FT_FAILURE);
	else if (is_word_string(cur_elem))
		check = wordstring_expect(next_elem);
	else if (is_redirection(cur_elem))
		check = symbol_expect(next_elem);
	else if (is_dless(cur_elem))
		check = dless_expect(next_elem);
	else if (is_l_parenthesis(cur_elem))
		check = lparenthesis_expect(next_elem);
	else if (is_r_parenthesis(cur_elem))
		check = rparenthesis_expect(next_elem);
	return (check);
}
