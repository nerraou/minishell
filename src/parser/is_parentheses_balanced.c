/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parentheses_balanced.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:47:18 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/25 12:35:49 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int is_parentheses_balanced(t_list *list)
{
	t_element *elm;
	t_token *token;
	int check;

	elm = list->head;
	check = 0;
	while (elm)
	{
		token = (t_token *)elm->content;
		if (token->type == T_L_PARENTH)
			check++;
		else if (token->type == T_R_PARENTH)
			check--;
		if (check < 0)
			return 0;
		elm = elm->next;
	}
	if (check == 0)
		return 1;
	return 0;
}
