/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:38:41 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/06 16:41:17 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	check_end_of_line(char	*buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	return (i);
}


char	*ft_strjoin1(char **line, char **str)
{
	char	*temp;

	if (!*line && *str)
	{
		*line = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1));
		ft_strncpy(*line, *str, ft_strlen(*str) + 1);
		free(*str);
		*str = NULL;
		return (*line);
	}
	if (*line && *str)
	{
		temp = *line;
		*line = malloc(sizeof(char) * (ft_strlen(*line) + ft_strlen(*str) + 1));
		ft_strncpy(*line, temp, ft_strlen(temp));
		ft_strncpy(*line + ft_strlen(temp), *str, ft_strlen(*str) + 1);
		free(*str);
		*str = NULL;
		free(temp);
	}
	return (*line);
}

