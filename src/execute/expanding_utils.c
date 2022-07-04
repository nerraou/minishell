/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:01:36 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 12:39:23 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_befor(char **value, char **befor, int *i)
{
	if (*i > 0)
		*befor = ft_substr((*value), 0, *i);
	else
		*befor = NULL;
}

void	update_after(char **value, char **after, int j)
{
	int	end;

	end = j;
	while ((*value)[end])
		end++;
	if (end - j > 0)
		*after = ft_substr((*value), j + 1, end - j);
	else
		*after = NULL;
}

void	check_tilda(t_element **elm)
{
	t_token		*token;

	token = (t_token *)(*elm)->content;
	if (!ft_strcmp(token->value, "~"))
	{
		free(token->value);
		token->value = ft_strdup(g_vars.tilda);
	}
}
