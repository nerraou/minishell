/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:43:24 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 14:37:59 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char	*str1;
	unsigned const char	*str2;
	size_t				i;
	int					diff;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	diff = 0;
	while (str1[i] || str2[i])
	{
		diff = str1[i] - str2[i];
		if (diff != 0)
			break ;
		i++;
	}
	return (diff);
}
