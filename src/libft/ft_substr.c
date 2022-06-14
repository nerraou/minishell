/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:50:44 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/09 16:50:45 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		p = malloc(sizeof(char));
		if (!p)
			return (0);
		*p = 0;
		return (p);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_strlcpy(p, s + start, len + 1);
	p[len + 1] = '\0';
	return (p);
}