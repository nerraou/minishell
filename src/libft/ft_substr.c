/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:36:33 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 11:50:03 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;
	size_t size;

	size = ft_strlen(s);
	if (start > size)
		return (NULL);
	if (size < len)
		len = size;
	str = (char *)ft_malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strncpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}