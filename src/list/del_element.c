/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:00:34 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/20 11:44:34 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_element_token(t_element *elm)
{
	t_token	*token;

	if (elm->next)
		elm->next->prev = elm->prev;
	if (elm->prev)
		elm->prev->next = elm->next;
	token = (t_token *)elm->content;
	free(token->value);
	free(token);
	free(elm);
}
