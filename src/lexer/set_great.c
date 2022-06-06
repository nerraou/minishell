/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_great.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:37:27 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 11:50:23 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int set_great(const char *str, t_list *list)
{
	t_token *token;

	if (str[0] == '>')
	{
		token = ft_new_token(ft_strdup(">"), T_GREAT);
		if (!token)
			return -1;
		add_back(list, token);
		return 1;
	}
	return -1;
}