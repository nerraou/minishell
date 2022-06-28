/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:39:45 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/27 14:15:02 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_back(t_list *list, void *content)
{
	t_element	*elm;

	elm = elem_new(content);
	if (!elm)
		return ;
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
