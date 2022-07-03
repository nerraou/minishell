/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:17:54 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/03 16:47:31 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	joining(t_element *elm, t_token *token_next)
{
	t_token		*token;
	char		*holder;

	token = (t_token *)elm->content;
	holder = ft_strjoin(token->value, token_next->value);
	free(token->value);
	token->value = holder;
}

void	join_pieces(t_element *f_cmd, t_element *l_cmd)
{
	t_token		*token;
	t_element	*elm;
	t_element	*elm_next;
	bool		stop;

	stop = true;
	elm = f_cmd;
	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		if (elm->next)
			elm_next = elm->next;
		while (token->to_join == 1 && stop)
		{
			token = (t_token *)elm_next->content;
			joining(elm, token);
			token->type = -1;
			if (token->to_join == 0)
				stop = false;
			elm_next = elm_next->next;
		}
		elm = elm->next;
	}
}
