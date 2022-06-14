/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:43:34 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/11 18:01:31 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int parser(const char *str, t_list *list)
{
	t_element *elm;
	t_token *token;

	lexer(str, list);
	if (list->size == 0)
		return FT_SUCCESS;
	elm = list->head;
	if (check_start(elm))
		return FT_FAILURE;
	while (elm)
	{
		token = (t_token *)elm->content;
		if (expect(elm, elm->next) == 1)
			return FT_FAILURE;
		elm = elm->next;
	}
	return FT_SUCCESS;
}