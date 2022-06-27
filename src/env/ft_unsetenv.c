/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:51:33 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 11:31:32 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	ft_unsetenv(t_list *env_list, const char *key)
{
	t_element	*elm;

	elm = ft_getenv(env_list, key);
	if (!elm)
		return (0);
	del_env((t_env *)elm->content);
	if (elm->prev == NULL)
	{
		env_list->head = elm->next;
		if (elm->next != NULL)
			elm->next->prev = NULL;
	}
	else if (elm->next == NULL)
	{
		env_list->tail = elm->prev;
		env_list->tail->next = NULL;
	}
	else
	{
		elm->prev->next = elm->next;
		elm->next->prev = elm->prev;
	}
	free(elm);
	env_list->size--;
	return (0);
}
