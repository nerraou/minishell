/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:26:19 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 12:25:36 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_array(t_list *env_list)
{
	char	**arr;
	int		index;
	int		i;

	arr = list_to_array(env_list);
	sort_array(arr, env_list->size);
	i = 0;
	while (arr[i])
	{
		index = ft_indexof(arr[i], '=');
		printf("declare -x %.*s\"%s\"\n", index + 1, arr[i], arr[i] + index + 1);
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	is_valid_env(const char *env)
{
	int	index;

	index = ft_indexof(env, '=');
	if (index != -1 && is_var_name(env, index))
		return (1);
	return (0);
}

static void	print_export_error(char *str)
{
	int	index;

	index = ft_indexof(str, '=');
	if (is_var_name(str, index))
		return ;
	ft_putstr_fd("minishell: export: ", 2);
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\'', 2);
	ft_putendl_fd(": not a valid identifier", 2);
}

int	export(int ac, char *av[], t_list *env_list)
{
	int		i;
	t_env	*env;

	i = 1;
	if (ac == 1)
		print_array(env_list);
	while (i < ac)
	{
		if (is_valid_env(av[i]))
		{
			env = new_env(av[i]);
			ft_setenv(env_list, env);
		}
		else
			print_export_error(av[i]);
		i++;
	}
	return (FT_SUCCESS);
}
