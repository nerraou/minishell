/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:22:55 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/05 15:42:25 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_element	*find_heredoc_delimiter(t_element *last_pos)
{
	t_token	*token;

	while (last_pos)
	{
		token = (t_token *)last_pos->content;
		if (token->type == T_DLESS)
			return (last_pos->next);
		last_pos = last_pos->next;
	}
	return (NULL);
}

static void	join_content(char **line, char **full_content)
{
	char	*to_free;

	to_free = *full_content;
	*full_content = ft_strjoin(*full_content, *line);
	free(to_free);
	to_free = *full_content;
	*full_content = ft_strjoin(*full_content, "\n");
	free(to_free);
	free(*line);
	*line = NULL;
}

static t_list	*dummy_function(char *str, t_list *heredoc_list)
{
	free(str);
	return (heredoc_list);
}

static t_element	*dummy_function2(t_element *last_pos, char *line)
{
	t_element	*l_pos;

	l_pos = find_heredoc_delimiter(last_pos);
	free (line);
	return (l_pos);
}

t_list	*heredoc(int heredoc_num, t_list *list)
{
	t_list		*heredoc_list;
	t_element	*last_pos;
	t_token		*token;
	char		*line;
	char		*full_content;

	heredoc_list = list_new();
	last_pos = find_heredoc_delimiter(list->head);
	full_content = ft_strdup("");
	while (heredoc_num > 0)
	{
		g_vars.heredoc = T_DLESS;
		line = readline("> ");
		token = (t_token *)last_pos->content;
		if (line && ft_strcmp(line, token->value) != 0)
			join_content(&line, &full_content);
		else
		{
			add_back(heredoc_list, full_content);
			full_content = ft_strdup("");
			heredoc_num--;
			last_pos = dummy_function2(last_pos, line);
		}
	}
	return (dummy_function(full_content, heredoc_list));
}
