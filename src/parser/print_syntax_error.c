/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:05:38 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/11 17:00:05 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void print_syntax_error(t_element *elem)
{
	t_token *token;

	if (!elem)
		ft_putendl_fd("minishell: syntax error unexpected end of file ", 2);
	else
	{
		token = (t_token *)elem->content;
		if (token->type == T_NEWLINE)
			ft_putendl_fd("minishell:  syntax error near unexpected token \'newline\'", 2);
		else
		{
			ft_putstr_fd("minishell:  syntax error near unexpected token ", 2);
			ft_putchar_fd('\'', 2);
			ft_putstr_fd(token->value, 2);
			ft_putendl_fd("'", 2);
		}
	}
}
