/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:56:49 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/23 17:17:52 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long ft_atol(const char *str)
{
	int i;
	long sign;
	long num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}
