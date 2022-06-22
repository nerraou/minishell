/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:49:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/22 13:39:25 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
// handle the env

void chang

	int
	cd(int ac, char *av[], t_list *env)
{
	int check;
	t_element *elm;
	t_env *home_env;
	if (ac == 1)
	{
		elm = ft_getenv(env, "HOME");
		if (!elm)
			return 1;
		home_env = (t_env *)elm->content;
		check = chdir(home_env->value);
		if (check == -1)
		{
			printf("minishell: %s\n", strerror(errno));
			return FT_FAILURE;
		}
		pwd();

		return FT_SUCCESS;
	}
	else
	{
		check = chdir(av[1]);
		if (check == -1)
		{
			printf("minishell: %s\n", strerror(errno));
			return FT_FAILURE;
		}
		pwd();
	}

	return FT_SUCCESS;
}
