/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:05:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/21 09:58:36 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int ft_setenv(t_list *env_list, t_env *env)
{
	t_element *elm;

	elm = ft_getenv(env_list, env->key);
	if (elm)
	{
		del_env((t_env *)elm->content);
		elm->content = env;
	}
	else
		add_back(env_list, env);
	return 0;
}
