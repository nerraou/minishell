/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:17:54 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/01 12:59:01 by obelkhad         ###   ########.fr       */
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
	t_token		*token_next;
	t_token		*token;
	t_element	*elm;
	bool		stop;

	stop = true;
	elm = f_cmd;
	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		while (token->to_join == 1 && stop)
		{
			token_next = (t_token *)elm->next->content;
			if (token_next->to_join == 0)
				stop = false;
			joining(elm, token_next);
			token_next->type = -1;
		}
		elm = elm->next;
	}
}
