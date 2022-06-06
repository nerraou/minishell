/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:34:21 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 11:50:11 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_skip_spaces(const char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return i;
}