/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dgreat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:57:07 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/03 17:34:12 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int set_dgreat(const char *str, t_list *list)
{
	t_token *token;

	if (ft_strncmp(str, ">>", 2) == 0)
	{
		token = ft_new_token(ft_strdup(">>"), T_DGREAT);
		if (!token)
			return -1;
		add_back(list, token);
		return 2;
	}
	return -1;
}