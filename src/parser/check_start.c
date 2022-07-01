/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:02:16 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/01 18:36:17 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_start(t_element *elm)
{
	if (is_separator(elm))
	{
		print_syntax_error(elm);
		return (FT_FAILURE);
	}
	return (FT_SUCCESS);
}
