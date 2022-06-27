/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:04:37 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/27 14:20:41 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int empty_prompt(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\n' || \
	cmd[i] == '\v' || cmd[i] == '\f' || cmd[i] == '\r'))
		i++;
	if (!cmd[i])
		return (1);
	return (0);
}

void	ctr_d(void)
{
	write(1, "\033[1A\033[12Cexit\n", ft_strlen("\033[1A\033[12Cexit\n"));
	exit (0);
}

// clear history

void	sig_handel(int sig)
{


	// if (sig == SIGINT && global_vars.heredoc == T_DLESS)
	// {
	// 	// printf("LL\n");
	// 	// global_vars.heredoc = 1;
	// 	// rl_insert_text("osama$");
	// 	// // rl_on_new_line();
	// 	// rl_redisplay();
	// 	// global_vars.heredoc = 1;
	// 	global_vars.exit_code = 1;
	// }
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGINT && global_vars.heredoc != T_DLESS)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		global_vars.exit_code = 1;
	}
}