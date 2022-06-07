/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dless_expect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:31:25 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/11 16:44:52 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int dless_expect(t_element *next_elem)
{

	if (next_elem == NULL || !is_word_string(next_elem))
	{
		print_syntax_error(next_elem);
		return FT_FAILURE;
	}
	return FT_SUCCESS;
}
