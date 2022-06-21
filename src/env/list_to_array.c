/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:20:38 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/21 14:47:53 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char **list_to_array(t_list *env_list)
{
	char **env_arr;
	t_element *elm;
	t_env *env;
	int i;

	env_arr = (char **)ft_malloc(sizeof(char *) * (env_list->size + 1));
	if (!env_arr)
		return NULL;
	i = 0;
	elm = env_list->head;
	while (elm)
	{
		env = (t_env *)elm->content;
		env_arr[i] = ft_strdup(env->prepared);
		i++;
		elm = elm->next;
	}
	return (env_arr);
}