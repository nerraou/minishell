/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:27:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/09 10:34:14 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int set_or(const char *str, t_list *list)
{
	t_token *token;

	if (str[0] == '|' && str[1] == '|')
	{
		token = ft_new_token(ft_strdup("||"), T_OR);
		if (!token)
			return -1;
		add_back(list, token);
		return 2;
	}
	return -1;
}