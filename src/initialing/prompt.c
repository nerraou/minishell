/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 07:47:00 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/18 17:05:30 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

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
	int 	result;
	int		heredoc_num = 0;
	t_list *heredoc_list;

	while (1)
	{
		list = list_new();
		// struct termios tp;
		// if (tcgetattr(STDIN_FILENO, &tp))
		// 	perror("tcgetattr");
		// tp.c_lflag &= ~ECHOCTL;
		// if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp))
		// 	perror("tcsetattr");
		cmd = readline(_prompt);
		result = parser(cmd, list, &heredoc_num);
		if (result == FT_REPROMPT)
		{
			heredoc_list = heredoc(&heredoc_num, list);
			result = FT_SUCCESS;
		}
		if (result == FT_SUCCESS)
		{
			if (!empty_prompt(cmd))
			{
				history(cmd, envp);
				priority_handling(list->head, list->tail, envp, heredoc_list);
			}
		}
		if (result == FT_FAILURE)
		{
			free(cmd);
			list_del(&list, free);
		}
		if (heredoc_num == 0)
			break;
	}
}