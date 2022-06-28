/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_expect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:26:44 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 09:50:07 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	symbol_expect(t_element *next_elem)
{
	if (next_elem == NULL || !is_word_string(next_elem))
	{
		print_syntax_error(next_elem);
		return (FT_FAILURE);
	}
	return (FT_SUCCESS);
}
