/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:15:47 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 11:50:08 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token *ft_new_token(char *value, int type)
{
	t_token *token;
	if (!value)
		return NULL;
	token = (t_token *)ft_malloc(sizeof(t_token));
	if (!token)
		return NULL;
	token->value = value;
	token->type = type;
	return token;
}