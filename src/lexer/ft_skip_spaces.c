/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:34:21 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/01 10:46:26 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_skip_spaces(const char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return i;
}