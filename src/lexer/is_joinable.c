/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_joinable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:31:41 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/03 17:25:39 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	is_redirection(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

static int	is_separator(char c)
{
	if (c == '|' || c == '&')
		return (1);
	return (0);
}

int	is_joinable(char c)
{
	if (!is_redirection(c) && !is_separator(c) && !ft_isspace(c)
		&& c != ')' && c != '\n')
		return (1);
	return (0);
}
