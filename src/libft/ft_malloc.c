/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:12:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 11:49:46 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void *ft_malloc(size_t size)
{
	void *arr;

	arr = malloc(size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, size);
	return (arr);
}
