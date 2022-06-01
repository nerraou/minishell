/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dgreat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:57:07 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/01 16:01:18 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int set_dgreat(const char *str, t_list *list)
{
	t_token *token;

	if (ft_strncmp(str, ">>", 2) == 0)
	{
		token = (t_token *)malloc(sizeof(t_token));
		if (!token)
			return -1;
		token->value = ft_strdup(">>");
		token->type = T_DGREAT;
		add_back(list, token);
		return 2;
	}
	return -1;
}