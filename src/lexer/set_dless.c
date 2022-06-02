/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dless.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:55:53 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/01 16:52:50 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int set_dless(const char *str, t_list *list)
{
	t_token *token;

	if (ft_strncmp(str, "<<", 2) == 0)
	{
		token = (t_token *)malloc(sizeof(t_token));
		if (!token)
			return -1;
		token->value = ft_strdup("<<");
		token->type = T_DLESS;
		add_back(list, token);
		return 2;
	}
	return -1;
}