/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 09:18:34 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/29 09:29:20 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


void del_token(void *content)
{
	t_token *token;
	
	token = (t_token *)content;
	free(token->value);
	free(token);
}