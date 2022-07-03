/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:49:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/01 19:02:42 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
// handle the env

void	change_pwd(char *new_pwd, t_list *env)
{
	t_element	*elm;
	t_env		*old_path;
	char		*old_pwd;

	elm = ft_getenv(env, "PWD");
	old_path = (t_env *)elm->content;
	old_pwd = old_path->value;
	new_pwd = ft_strjoin("PWD=", new_pwd);
	old_pwd = ft_strjoin("OLDPWD=", old_pwd);
	ft_setenv(env, new_env(new_pwd));
	ft_setenv(env, new_env(old_pwd));
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
			printf("minishell: cd: %s: %s\n",av[1], strerror(errno));
			return (FT_FAILURE);
		}
		change_pwd(getcwd(NULL, 0), env);
	}
	return (FT_SUCCESS);
}
