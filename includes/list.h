/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:28:25 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 11:42:52 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

typedef struct s_element
{
	void *content;
	struct s_element *next;
	struct s_element *prev;
} t_element;

typedef struct s_list
{
	t_element *head;
	t_element *tail;
	int size;
} t_list;

t_element *elem_new(void *content);
t_list *list_new(void);

void add_front(t_list *list, void *content);
void add_back(t_list *last, void *content);
void list_del(t_list **lst, void (*del)(void *));

#endif