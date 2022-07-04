/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:00:34 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/03 17:39:02 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_element_token(t_element *elm)
{
	t_token		*token;

	if (elm->next)
		elm->next->prev = elm->prev;
	if (elm->prev)
		elm->prev->next = elm->next;
	token = (t_token *)elm->content;
}
