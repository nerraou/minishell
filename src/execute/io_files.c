/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:22:58 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/20 16:07:38 by obelkhad         ###   ########.fr       */
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
	write(fd, token->value, ft_strlen(token->value));
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
	dup2(fd, STDIN_FILENO);
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
	dup2(fd, STDOUT_FILENO);
	close(fd);
}


void	less_great_dgreat(t_element	*elm)
{
	t_token		*token;
	t_token		*_file;

	// elm = elm->next;
	token = (t_token *)elm->content;
	_file = (t_token *)elm->next->content;
	if (token->type == T_LESS)
		open_file_read(ft_strdup(_file->value));
	else if (token->type == T_GREAT)
		open_file_write(ft_strdup(_file->value), 0);
	else if (token->type == T_DGREAT)
		open_file_write(ft_strdup(_file->value), 1);
	del_element_token(elm->next);
	elm = elm->next;
	del_element_token(elm->prev);
}

void	dless(t_element	*elm)
{
	heredoc_to_file(elm->next);
	del_element_token(elm->next);
	elm = elm->next;
	del_element_token(elm->prev);
	open_file_read("heredoc");
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
		token = (t_token *)elm->content;
		if (!token->type >= T_LESS && token->type <= T_DLESS)
			elm = elm->next;
	}
}