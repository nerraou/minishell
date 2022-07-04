/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:00:30 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/04 09:53:55 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file_read(char	*infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		write(2, "minishell: ", ft_strlen("minishell: "));
		perror (infile);
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	open_file_write(char *outfile, int mode)
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
		write(2, "minishell: ", ft_strlen("minishell: "));
		perror (outfile);
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}
