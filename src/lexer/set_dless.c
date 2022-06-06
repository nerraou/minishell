/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dless.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:55:53 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 11:50:20 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int set_dless(const char *str, t_list *list)
{
	t_token *token;

	if (ft_strncmp(str, "<<", 2) == 0)
	{
		token = ft_new_token(ft_strdup("<<"), T_DLESS);
		if (!token)
			return -1;
		add_back(list, token);
		return 2;
	}
	return -1;
}