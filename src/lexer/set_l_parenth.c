/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_l_parenth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:44:57 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 09:59:12 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_l_parenth(const char *str, t_list *list)
{
	t_token	*token;

	if (str[0] == '(')
	{
		token = ft_new_token(ft_strdup("("), T_L_PARENTH);
		if (!token)
			return (-1);
		add_back(list, token);
		return (1);
	}
	return (-1);
}
