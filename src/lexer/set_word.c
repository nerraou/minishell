/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:59:09 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 11:50:35 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int word_len(const char *str)
{
	int i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]) && str[i] != '\n')
	{
		i++;
	}
	return i;
}

int set_word(const char *str, t_list *list)
{
	int t_len;
	t_token *token;

	t_len = word_len(str);
	if (t_len == 0)
		return -1;
	token = ft_new_token(ft_substr(str, 0, t_len), T_WORD);
	if (!token)
		return -1;
	add_back(list, token);
	return t_len;
}