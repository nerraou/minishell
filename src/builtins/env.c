/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:37:17 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/18 10:52:10 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int env(t_list *env_list)
{

	t_element *elem;
	t_env *env_elm;
	int i;

	elem = env_list->head;
	i = 0;
	while (env_list->size > i)
	{
		env_elm = (t_env *)elem->content;
		// printf("%s\n", env_elm->key);
		// printf("%s\n", env_elm->value);
		printf("%s\n", env_elm->prepared);
		elem = elem->next;
		i++;
	}
	return FT_SUCCESS;
}