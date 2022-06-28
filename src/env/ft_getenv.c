/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:37:19 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 11:30:05 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_element	*ft_getenv(t_list *env, const char *key)
{
	t_element	*elm;
	t_env		*env_var;

	elm = env->head;
	while (elm)
	{
		env_var = (t_env *)elm->content;
		if (ft_strcmp(env_var->key, key) == 0)
			return (elm);
		elm = elm->next;
	}
	return (NULL);
}
