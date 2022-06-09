/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 07:47:00 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/09 11:34:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	empty_prompt(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\n' ||\
		cmd[i] == '\v' || cmd[i] == '\f' || cmd[i] == '\r'))
		i++;
	if (!cmd[i])
		return (1);
	return (0);
}

void	prompt(char *_prompt, char **envp)
{
	t_list	*list;
	char	*cmd;

	list = list_new();
	while (1)
	{
		struct termios tp;
		if (tcgetattr(STDIN_FILENO, &tp))
			perror("tcgetattr");
		tp.c_lflag &= ~ECHOCTL;
		if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp))
			perror("tcsetattr");
		cmd = readline(_prompt);
		if (!empty_prompt(cmd))
		{
			history(cmd, envp);
			lexer(cmd, list);
			execut(list);
		}
		free(cmd);
	}
}