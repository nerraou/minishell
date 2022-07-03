/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_heredoc_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:31:49 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/26 19:23:58 by obelkhad         ###   ########.fr       */
/*                                                                            `*/
/* ************************************************************************** */

#include "parser.h"

static void del(void *content)
{
	(void)content;
}

void move_heredoc_content(t_list *list, t_list *heredoc_list)
{
	t_element *elm;
	t_element *herdoc_elm;
	t_token *token;

	herdoc_elm = heredoc_list->head;
	elm = list->head;
	while (elm)
	{
		token = (t_token *)elm->content;
		if (token->type == T_DLESS)
		{

			free(token->value);
			token->value = (char *)herdoc_elm->content;
			herdoc_elm = herdoc_elm->next;
		}
		elm = elm->next;
	}
	list_del(&heredoc_list, del);
}