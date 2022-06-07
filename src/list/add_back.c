/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:39:45 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 16:41:17 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void add_back(t_list *list, void *content)
{
	t_element *elm;

	elm = elem_new(content);
	if (!elm)
		return;
	if (!list->head)
		list->head = elm;
	if (!list->tail)
		list->tail = elm;
	else
	{
		list->tail->next = elm;
		elm->prev = list->tail;
		list->tail = elm;
	}
	list->size++;
}