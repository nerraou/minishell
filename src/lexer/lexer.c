/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:49:39 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 16:41:17 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void lexer(const char *str, t_list *list)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (str[i])
	{
		i += ft_skip_spaces(str + i);
		len = set_d_string(str + i, list);
		if (len == -1)
			len = set_s_string(str + i, list);
		if (len == -1)
			len = set_dless(str + i, list);
		if (len == -1)
			len = set_dgreat(str + i, list);
		if (len == -1)
			len = set_great(str + i, list);
		if (len == -1)
			len = set_less(str + i, list);
		if (len == -1)
			len = set_pipe(str + i, list);
		if (len == -1)
			len = set_newline(str + i, list);
		if (len == -1)
			len = set_word(str + i, list);
		if (str[i] && len == -1)
			i++;
		else if (str[i])
			i += len;
	}
}
