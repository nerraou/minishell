/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:26:19 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/18 19:47:54 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int is_valid_env(const char *env)
{
	int index;

	index = ft_indexof(env, '=');
	if (index != -1 && is_valid_var_name(env, index))
		return 1;
	return 0;
}

static void print_export_error(char *str)
{
	int index;

	index = ft_indexof(str, '=');

	if (is_valid_var_name(str, index))
		return;
	ft_putstr_fd("minishell: export: ", 2);
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\'', 2);
	ft_putendl_fd(": not a valid identifier", 2);
}

static t_element *find_env(t_list *env, t_env *to_find)
{
	t_element *elm;
	t_env *env_var;
	elm = env->head;
	while (elm)
	{
		env_var = (t_env *)elm->content;
		if (ft_strcmp(env_var->key, to_find->key) == 0)
			return (elm);
		elm = elm->next;
	}
	return (NULL);
}

static void update_env(t_element *elm, t_env *env)
{
	del_env((t_env *)elm->content);
	elm->content = env;
}

int export(int ac, char *av[], t_list *env_list)
{
	int i;
	t_env *env;
	t_element *elm;
	i = 1;
	while (i < ac)
	{
		if (is_valid_env(av[i]))
		{
			env = new_env(av[i]);
			elm = find_env(env_list, env);
			if (elm)
				update_env(elm, env);
			else
				add_back(env_list, env);
		}
		else
			print_export_error(av[i]);
		i++;
	}
	return FT_SUCCESS;
}
