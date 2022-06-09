/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:27:51 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/09 10:29:24 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int set_and(const char *str, t_list *list)
{
	t_token *token;

	if (str[0] == '&' && str[1] == '&')
	{
		token = ft_new_token(ft_strdup("&&"), T_AND);
		if (!token)
			return -1;
		add_back(list, token);
		return 1;
	}
	return -1;
}