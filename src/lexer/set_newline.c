/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_newline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:41:11 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/03 17:38:32 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int set_newline(const char *str, t_list *list)
{
	t_token *token;

	if (str[0] == '\n')
	{
		token = ft_new_token(ft_strdup("\n"), T_NEWLINE);
		if (!token)
			return -1;
		add_back(list, token);
		return 1;
	}
	return -1;
}