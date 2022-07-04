/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:49:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/03 18:36:39 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	change_pwd(char *new_pwd, t_list *env)
{
	t_element	*elm;
	t_env		*old_path;
	char		*old_pwd;

	elm = ft_getenv(env, "PWD");
	if (elm)
	{
		old_path = (t_env *)elm->content;
		old_pwd = old_path->value;
		old_pwd = ft_strjoin("OLDPWD=", old_pwd);
		ft_setenv(env, new_env(old_pwd));
		free(old_pwd);
	}
	new_pwd = ft_strjoin("PWD=", new_pwd);
	ft_setenv(env, new_env(new_pwd));
	free(new_pwd);
}

static int	ft_cd(t_list *env)
{
	int			check;
	t_element	*elm;
	t_env		*home_env;

	elm = ft_getenv(env, "HOME");
	if (!elm)
		return (FT_FAILURE);
	home_env = (t_env *)elm->content;
	check = chdir(home_env->value);
	if (check == -1)
	{
		printf("minishell: %s\n", strerror(errno));
		return (FT_FAILURE);
	}
	change_pwd(getcwd(NULL, 0), env);
	return (FT_SUCCESS);
}

static void	print_cd_error(char *msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd(' ', 2);
	ft_putendl_fd(strerror(errno), 2);
}

int	cd(int ac, char *av[], t_list *env)
{
	int			check;

	if (ac == 1)
		return (ft_cd(env));
	else
	{
		check = chdir(av[1]);
		if (check == -1)
		{
			print_cd_error(av[1]);
			return (FT_FAILURE);
		}
		change_pwd(getcwd(NULL, 0), env);
	}
	return (FT_SUCCESS);
}
