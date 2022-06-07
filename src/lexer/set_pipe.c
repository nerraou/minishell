/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:25:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/10 09:20:40 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int set_pipe(const char *str, t_list *list)
{
	t_token *token;

	if (str[0] == '|')
	{
		token = ft_new_token(ft_strdup("|"), T_PIPE);
		if (!token)
			return -1;
		add_back(list, token);
		return 1;
	}
	return -1;
}
