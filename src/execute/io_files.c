/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:22:58 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/19 19:00:24 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_to_file(t_element *heredoc_content)
{
	int		fd;
	int		flags;
	t_token	*token;

	token = (t_token *)heredoc_content->content;
	flags = O_TRUNC | O_CREAT | O_WRONLY;
	fd = open("heredoc", flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	/*EXPEAND $HOME*/
	write(fd, token->value, ft_strlen(content));
	close(fd);
}

void	open_file_read(char	*infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		/*free*/
		write(2, "minish: ",8);
		perror (infile);
		free(infile);
		exit(1);
	}
	free(infile);
	// dup2();
	close(fd);
}

void	open_file_write(char *outfile, int mode)
{
	int	fd;
	int	flags;

	if (mode)
		flags = O_APPEND | O_CREAT | O_WRONLY;
	else
		flags = O_TRUNC | O_CREAT | O_WRONLY;

	fd = open(outfile, flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		/*free*/
		write(2, "minish: ",8);
		perror (outfile);
		free(outfile);
		exit (1);
	}
	free(outfile);
	// dup2();
	close(fd);
}


void	less_great_dgreat(t_element	*elm)
{
	elm = elm->next;
	token = (t_token *)elm->content;
	if (token->type == T_LESS)
		open_file_read(ft_strdup(token->value));
	if (token->type == T_GREAT)
		open_file_write(ft_strdup(token->value), 0);
	if (token->type == T_DGREAT)
		open_file_write(ft_strdup(token->value), 1);
	del_element_token(elm->prev);
	elm = elm->next;
	del_element_token(elm->prev);
	elm = elm->prev;
}

void	dless(t_element	*elm)
{
	heredoc_to_file(elm->next);
	elm = elm->next;
	del_element_token(elm->prev);
	elm = elm->next;
	del_element_token(elm->prev);
	open_file_read("heredoc");
	elm = elm->prev;
}

void	get_io(t_element *f_cmd, t_element *l_cmd)
{
	t_element	*elm;
	t_token		*token;

	elm = f_cmd;
	while (elm &&elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		if (token->type >= T_LESS && token->type <= T_DGREAT)
			less_great_dgreat(elm);
		if (token->type == T_DLESS)
			dless(elm);
		elm = elm->next;
	}
}