/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_s_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:10:12 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/01 18:40:44 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	is_string(const char *str, int *t_len)
{
	int	i;

	i = 0;
	if (str[i] == '\'')
		i++;
	else
		return (0);
	while (str[i])
	{
		if (str[i] == '\'')
		{
			*t_len = i + 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int	set_s_string(const char *str, t_list *list)
{
	int		t_len;
	t_token	*token;

	t_len = 0;
	if (!is_string(str, &t_len))
		return (-1);
	token = ft_new_token(ft_substr(str, 1, t_len - 2), T_S_STRING);
	if (!token)
		return (-1);
	if (str[t_len] && is_joinable(str[t_len]))
		token->to_join = TRUE;
	add_back(list, token);
	return (t_len);
}
