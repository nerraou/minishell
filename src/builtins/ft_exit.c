/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:52:21 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/23 14:35:35 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void ft_exit(int ac, char *av[])
{
	int check;
	if (ac > 1)
	{
		check = is_long(av[1]);
		if (check == 1)
			printf("YES IS A LONG NUMBER\n");
		else
			printf("NO IS NOT A LONG NUMBER\n");
	}
}