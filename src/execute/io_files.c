/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:22:58 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 09:52:37 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_to_file(char *heredoc_content)
{
	int		fd;
	int		flags;

	flags = O_TRUNC | O_CREAT | O_WRONLY;
	fd = open("heredoc", flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	write(fd, heredoc_content, ft_strlen(heredoc_content));
	close(fd);
}

int	less_great_dgreat(t_element	*elm)
{
	t_token		*token;
	t_token		*_file;

	token = (t_token *)elm->content;
	_file = (t_token *)elm->next->content;
	if (token->type == T_LESS)
		return (open_file_read(_file->value));
	else if (token->type == T_GREAT)
		return (open_file_write(_file->value, 0));
	else if (token->type == T_DGREAT)
		return (open_file_write(_file->value, 1));
	return (0);
}

void	dless(t_element	*elm)
{
	t_token		*lim;
	t_token		*content_heredoc;

	lim = (t_token *)elm->next->content;
	content_heredoc = (t_token *)elm->content;
	heredoc_to_file(content_heredoc->value);
	open_file_read("heredoc");
}

int	get_io(t_element *f_cmd, t_element *l_cmd)
{
	t_element	*elm;
	t_token		*token;
	int			error_file;

	error_file = 0;
	elm = f_cmd;
	while (elm && elm->prev != l_cmd && !error_file)
	{
		token = (t_token *)elm->content;
		if (token->type == T_LESS || token->type == T_GREAT || \
		token->type == T_DGREAT)
			error_file = less_great_dgreat(elm);
		else if (token->type == T_DLESS)
			dless(elm);
		elm = elm->next;
	}
	return (error_file);
}
