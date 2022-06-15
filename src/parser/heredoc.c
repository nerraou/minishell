/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:22:55 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/15 17:16:27 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int ft_setherdoc_list(const char *heredoc_cmd, const char *end, t_list *heredoc_list)
{

	if (ft_strcmp(heredoc_cmd, end) != 0)
	{
		add_back(heredoc_list, ft_strjoin(heredoc_cmd, "\n"));
		return 0;
	}
	else
		return 1;
}

static t_element *find_heredoc_delimiter(t_element *last_pos)
{
	t_token *token;
	token = (t_token *)last_pos->content;
	while (last_pos)
	{
		token = (t_token *)last_pos->content;
		if (token->type == T_DLESS)
			return last_pos->next;
		last_pos = last_pos->next;
	}
	return NULL;
}

static int ft_heredoc(const char *heredoc_cmd, t_list *heredoc_list, t_element *last_pos)
{

	t_token *token;
	if (!last_pos)
		return 1;
	token = (t_token *)last_pos->content;
	return ft_setherdoc_list(heredoc_cmd, token->value, heredoc_list);
}

t_list *heredoc(int *heredoc_num, t_list *list)
{
	t_list *heredoc_list;
	char *heredoc_cmd;
	t_element *last_pos;

	heredoc_list = list_new();
	last_pos = list->head;
	last_pos = find_heredoc_delimiter(last_pos);
	while (*heredoc_num > 0)
	{
		heredoc_cmd = readline("> ");
		if (ft_heredoc(heredoc_cmd, heredoc_list, last_pos) == 1)
		{
			(*heredoc_num)--;
			last_pos = find_heredoc_delimiter(last_pos);
		}
		free(heredoc_cmd);
	}
	return (heredoc_list);
}
