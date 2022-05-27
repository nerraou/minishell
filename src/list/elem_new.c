/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:37:02 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/27 15:37:05 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_element *elem_new(void *content)
{
	t_element *new_elm;

	new_elm = (t_element *)malloc(sizeof(t_element));
	if (!new_elm)
		return (NULL);
	new_elm->content = content;
	new_elm->next = NULL;
	return (new_elm);
}