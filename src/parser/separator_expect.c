/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator_expect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:24:06 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/11 16:01:59 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int separator_expect(t_element *next_elem)
{
	if (next_elem == NULL || is_separator(next_elem))
	{
		print_syntax_error(next_elem);
		return FT_FAILURE;
	}
	return FT_SUCCESS;
}