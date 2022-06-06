/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:38:51 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 11:49:59 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char *str1;
	unsigned const char *str2;
	size_t i;
	int diff;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	diff = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		diff = str1[i] - str2[i];
		if (diff != 0)
			break;
		i++;
	}
	return (diff);
}