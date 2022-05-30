/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:11:56 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/30 18:12:10 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_string(char *str, int *t_len)
{
	int i;

	i = 0;
	if (str[i] == '"')
		i++;
	else
		return 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			*t_len = i + 1;
			return 1;
		}
		i++;
	}
	return 0;
}
