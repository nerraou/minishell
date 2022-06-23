/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:43:34 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/23 16:32:49 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int parser(const char *str, t_list *list, int *heredoc)
{
	t_element *elm;
	t_token *token;

	*heredoc = 0;
	lexer(str, list);
	if (list->size == 0)
		return FT_SUCCESS;
	elm = list->head;
	if (check_start(elm))
		return FT_FAILURE;
	while (elm)
	{
		token = (t_token *)elm->content;
		if (token->type == T_DLESS)
			(*heredoc)++;
		if (expect(elm, elm->next) == FT_FAILURE)
			return FT_FAILURE;

		elm = elm->next;
	}
	if (*heredoc > 0)
		return FT_REPROMPT;
	return FT_SUCCESS;
}
