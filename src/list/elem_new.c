/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:37:02 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/09 10:10:28 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_element *elem_new(void *content)
{
	t_element *new_elm;

	new_elm = (t_element *)ft_malloc(sizeof(t_element));
	if (!new_elm)
		return (NULL);
	new_elm->content = content;
	return (new_elm);
}
