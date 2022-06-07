/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:41:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/06 16:41:17 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_digits(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		counter++;
	while (n)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		dc;
	long	number;
	char	*str;

	number = n;
	dc = count_digits(number);
	str = malloc((dc + 1) * sizeof(char));
	if (!str)
		return (0);
	str[dc] = '\0';
	if (n < 0)
	{
		number *= -1;
		str[0] = '-';
	}
	while (number >= 0)
	{
		str[--dc] = number % 10 + '0';
		number = number / 10;
		if (number == 0)
			break ;
	}
	return (str);
}
