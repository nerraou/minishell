/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 07:47:00 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 12:38:02 by obelkhad         ###   ########.fr       */
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

int	herdoc_input(t_list *heredoc_list, char *cmd, t_list *list, t_list *env)
{
	int		result;
	int		heredoc_num;
	char	**env_arr;

	heredoc_num = 0;
	env_arr = list_to_array(env);
	history(cmd, env_arr);
	free_2_arr(env_arr);
	result = parser(cmd, list, &heredoc_num);
	if (result == FT_REPROMPT)
	{
		heredoc_list = heredoc(heredoc_num, list);
		move_heredoc_content(list, heredoc_list);
		result = FT_SUCCESS;
	}
	return (result);
}

void	prompt(char *_prompt, char **envp, t_list *env_list, int in)
{
	t_list	*list;
	char	*cmd;
	t_list	*hrdoc;

	hrdoc = NULL;
	g_vars.tilda = get_env_value("HOME=", envp);
	while (1)
	{
		list = list_new();
		g_vars.heredoc = 1;
		cmd = read_line(_prompt);
		if (!cmd)
			ctr_d();
		g_vars.heredoc = 0;
		if (herdoc_input(hrdoc, cmd, list, env_list) == FT_SUCCESS && \
		!empty_prompt(cmd))
		{
			priority(list->head, list->tail, env_list, in);
			unlink("heredoc");
		}
		free(cmd);
		list_del(&list, del_token);
	}
	free(g_vars.tilda);
}
