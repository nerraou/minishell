/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 07:47:00 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/26 20:43:53 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

char	*read_line(char *_prompt)
{
	struct termios	tp;
	char			*cmd;

	if (tcgetattr(STDIN_FILENO, &tp))
		perror("tcgetattr");
	tp.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp))
		perror("tcsetattr");
	cmd = readline(_prompt);
	return (cmd);
}

void prompt(char *_prompt, char **envp, int in)
{
	t_list *list;
	char *cmd;
	int result;
	int heredoc_num = 0;
	t_list *heredoc_list;

	while (1)
	{
		list = list_new();
		global_vars.heredoc = 1;
		cmd = read_line(_prompt);
		if (!cmd)
			ctr_d();
		result = parser(cmd, list, &heredoc_num);
		if (result == FT_REPROMPT)
		{
			heredoc_list = heredoc(heredoc_num, list);
			move_heredoc_content(list, heredoc_list);
			result = FT_SUCCESS;
		}
		if (result == FT_SUCCESS)
		{
			if (!empty_prompt(cmd))
			{
				history(cmd, envp);
				priority(list->head, list->tail, envp, in);
			}
		}
		if (result == FT_FAILURE)
		{
			free(cmd);
			list_del(&list, free);
		}
	}
}