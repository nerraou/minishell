/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_great.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:37:27 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/01 14:58:17 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int set_great(const char *str, t_list *list)
{
	t_token *token;

	if (str[0] == '>')
	{
		token = (t_token *)malloc(sizeof(t_token));
		if (!token)
			return -1;
		token->value = ft_strdup(">");
		token->type = T_GREAT;
		add_back(list, token);
		return 1;
	}
	return -1;
}