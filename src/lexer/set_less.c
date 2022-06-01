/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_less.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:55:20 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/01 15:06:41 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int set_less(const char *str, t_list *list)
{
	t_token *token;

	if (str[0] == '<')
	{
		token = (t_token *)malloc(sizeof(t_token));
		if (!token)
			return -1;
		token->value = ft_strdup("<");
		token->type = T_LESS;
		add_back(list, token);
		return 1;
	}
	return -1;
}