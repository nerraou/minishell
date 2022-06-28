/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:05:07 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 12:55:13 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_wild(t_wild *match)
{
	match->all_matches = NULL;
	match->file = NULL;
	match->holder = NULL;
}

void	update_element(t_element *elm, t_wild *match, int i)
{
	t_token	*token;

	if (i)
	{
		token = (t_token *)elm->content;
		free(token->value);
		token->value = ft_substr(match->all_matches, 0, \
		ft_strlen(match->all_matches) - 1);
	}
}

int	is_wildcard(t_element *elm)
{
	int		i;
	int		exist;
	t_token	*token;

	i = 0;
	exist = -1;
	token = (t_token *)elm->content;
	while (token->value[i])
	{
		if (token->value[i] == '*')
		{
			exist = i;
			break ;
		}
		i++;
	}
	return (exist);
}
