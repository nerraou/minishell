/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 07:47:00 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 13:43:28 by obelkhad         ###   ########.fr       */
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

int	herdoc_input(t_list	*heredoc_list, char *cmd, t_list *list)
{
	int		result;
	int		heredoc_num;

	heredoc_num = 0;
	result = parser(cmd, list, &heredoc_num);
	if (result == FT_REPROMPT)
	{
		heredoc_list = heredoc(heredoc_num, list);
		move_heredoc_content(list, heredoc_list);
		result = FT_SUCCESS;
	}
	return (result);
}

void	prompt(char *_prompt, char **envp, int in)
{
	t_list	*list;
	char	*cmd;
	t_list	*heredoc_list;

	heredoc_list = NULL;
	while (1)
	{
		list = list_new();
		global_vars.heredoc = 1;
		cmd = read_line(_prompt);
		global_vars.heredoc = 0;
		if (!cmd)
			ctr_d();
		if (herdoc_input(heredoc_list, cmd, list) == FT_SUCCESS && !empty_prompt(cmd))
		{
			
			history(cmd, envp);
			priority(list->head, list->tail, envp, in);
			unlink("heredoc");
		}
		free(cmd);
		list_del(&list, free);
	}
}
