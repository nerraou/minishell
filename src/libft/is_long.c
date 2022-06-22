/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:24:19 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/23 14:53:16 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_long(const char *str)
{
	int i;
	int sign;
	long count;

	i = 0;
	sign = 1;
	count = 0;
	if (!str[i])
		return (0);
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		count = count * 10 + str[i] - '0';
		if (count * sign > LONG_MAX || sign * count < LONG_MIN)
			return (0);
		i++;
	}
	return (1);
}
