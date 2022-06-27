/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_less.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:55:20 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 09:59:34 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	set_less(const char *str, t_list *list)
{
	t_token	*token;

	if (str[0] == '<')
	{
		token = ft_new_token(ft_strdup("<"), T_LESS);
		if (!token)
			return (-1);
		add_back(list, token);
		return (1);
	}
	return (-1);
}
