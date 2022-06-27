/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:37:15 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/27 14:15:34 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_front(t_list *list, void *content)
{
	t_element	*elm;

	elm = elem_new(content);
	if (!elm)
		return ;
	if (!list->tail)
		list->tail = elm;
	elm->next = list->head;
	if (list->head != NULL)
		list->head->prev = elm;
	list->head = elm;
	list->size++;
}
