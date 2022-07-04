/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:18:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 18:09:41 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	*env_list;
	char	**env_arr;
	int		in;

	in = dup(STDIN_FILENO);
	(void)argc;
	(void)argv;
	signal(SIGINT, sig_handel);
	signal(SIGQUIT, sig_handel);
	env_list = init_env(envp);
	env_arr = list_to_array(env_list);
	history(NULL, env_arr);
	prompt("MiniShell_$ ", env_arr, &env_list, in);
	list_del(&env_list, list_del_env);
	free_2_arr(env_arr);
	rl_clear_history();
	return (0);
}
