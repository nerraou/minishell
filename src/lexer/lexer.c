/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:49:39 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/03 12:10:16 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	set_string(const char *str, t_list *list)
{
	int	len;

	len = set_d_string(str, list);
	if (len == -1)
		len = set_s_string(str, list);
	return (len);
}

static int	set_symboles(const char *str, t_list *list)
{
	int	len;

	len = 0;
	len = set_l_parenth(str, list);
	if (len == -1)
		len = set_r_parenth(str, list);
	if (len == -1)
		len = set_or(str, list);
	if (len == -1)
		len = set_and(str, list);
	if (len == -1)
		len = set_dless(str, list);
	if (len == -1)
		len = set_dgreat(str, list);
	if (len == -1)
		len = set_great(str, list);
	if (len == -1)
		len = set_less(str, list);
	if (len == -1)
		len = set_pipe(str, list);
	return (len);
}

static int	check_quotes(const char *str)
{
	int		i;
	int		q_index;
	char	quote;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i];
			q_index = ft_indexof(str + i + 1, quote);
			if (q_index == -1)
				return (FT_FAILURE);
			i += q_index + 2;
		}
		else
			i++;
	}
	return (FT_SUCCESS);
}

static int increment_i(const char *str, int len, int i)
{
	if (str[i] && len == -1)
		i++;
	else if (str[i])
		i += len;
	return (i);
}

int	lexer(const char *str, t_list *list)
{
	int	i;
	int	len;

	i = 0;
	if (check_quotes(str) == FT_FAILURE)
		return (FT_FAILURE);
	while (str[i])
	{
		i += ft_skip_spaces(str + i);
		len = set_string(str + i, list);
		if (len == -1)
			len = set_symboles(str + i, list);
		if (len == -1)
		{
			len = set_newline(str + i, list);
			if (len != -1)
				break ;
		}
		if (len == -1)
			len = set_word(str + i, list);
		i = increment_i(str, len ,i);
	}
	return (FT_SUCCESS);
}
