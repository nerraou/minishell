/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:04:37 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/27 08:43:37 by obelkhad         ###   ########.fr       */
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

void	sig_handel(int sig)
{
	if (sig == SIGINT && global_vars.heredoc == T_DLESS)
		exit(1);
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		global_vars.exit_code = 0;
	}
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		global_vars.exit_code = 1;
	}
}