/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:12:45 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 11:49:47 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void *ft_memset(void *s, int c, size_t n)
{
	size_t i;
	unsigned char *str;

	str = s;
	i = 0;
	while (n > i)
	{
		*str = (unsigned char)c;
		str++;
		i++;
	}
	return (s);
}