/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:04:37 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/02 16:09:44 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	empty_prompt(char *cmd)
{
	int	i;

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
	if (sig == SIGINT && g_vars.heredoc == T_DLESS)
		g_vars.exit_code = 1;
	if (sig == SIGQUIT && g_vars.heredoc)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGINT && g_vars.heredoc != T_DLESS && g_vars.heredoc)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_vars.exit_code = 1;
	}
}
