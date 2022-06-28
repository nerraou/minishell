/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordstring_expect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:11:58 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 09:50:30 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	wordstring_expect(t_element *next_elm)
{
	if (next_elm == NULL || !is_l_parenthesis(next_elm))
		return (FT_SUCCESS);
	else
		print_syntax_error(next_elm);
	return (FT_FAILURE);
}
