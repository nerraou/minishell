/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:25:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/01 15:27:24 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int set_pipe(const char *str, t_list *list)
{
	t_token *token;

	if (str[0] == '|')
	{
		token = (t_token *)malloc(sizeof(t_token));
		if (!token)
			return -1;
		token->value = ft_strdup("|");
		token->type = T_PIPE;
		add_back(list, token);
		return 1;
	}
	return -1;
}