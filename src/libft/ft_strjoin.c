/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:55:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/06 16:41:17 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	unsigned int	l1;
	unsigned int	l2;

	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = malloc((l1 + l2 + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_memcpy(p, s1, l1);
	ft_strlcpy(p + l1, s2, l2 + 1);
	return (p);
}
