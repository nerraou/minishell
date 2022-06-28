/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:27:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 10:00:38 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	set_or(const char *str, t_list *list)
{
	t_token	*token;

	if (str[0] == '|' && str[1] == '|')
	{
		token = ft_new_token(ft_strdup("||"), T_OR);
		if (!token)
			return (-1);
		add_back(list, token);
		return (2);
	}
	return (-1);
}
