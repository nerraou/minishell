/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:36:45 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/04 17:11:01 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_del(t_list **lst, void (*del)(void *))
{
	t_element	*head;
	t_element	*next;

	next = NULL;
	head = (*lst)->head;
	if (head == NULL)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	while (head != NULL)
	{
		next = head->next;
		del(head->content);
		free(head);
		head = next;
	}
	free(*lst);
	*lst = NULL;
}
