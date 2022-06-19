/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:17:54 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/19 17:11:14 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	joining(t_element *elm)
{
	t_token		*token_next;
	t_token		*token;
	char	*holder;

	token = (t_token *)elm->content;
	token_next = (t_token *)elm->next->content;
	holder = ft_strjoin(token->value, token_next->value);
	free(token->value);
	token->value = holder;
	del_element_token(elm->next);
}

void	join_pieces(t_element *f_cmd, t_element *l_cmd)
{
	t_token		*token_next;
	t_token		*token;
	t_element	*elm;

	elm = f_cmd;
	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		while (token->to_join == 1)
		{
			token_next = (t_token *)elm->next->content;
			token->to_join = token_next->to_join;
			joining(elm);
		}
		elm = elm->next;
	}
}