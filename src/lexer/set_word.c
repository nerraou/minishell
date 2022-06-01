/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:59:09 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/01 17:37:26 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int word_len(const char *str)
{
	int i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
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
	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return -1;
	token->value = ft_substr(str, 0, t_len);
	token->type = T_WORD;
	add_back(list, token);
	return t_len;
}