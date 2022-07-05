/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:43:34 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/05 16:49:45 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	print_quotes_error(void)
{
	ft_putendl_fd("minishell: unexpected EOF while "
		"looking for matching quote", 2);
	return (FT_FAILURE);
}

static int	print_parentheses_error(void)
{
	ft_putendl_fd("minishell: parentheses are not balanced", 2);
	return (FT_FAILURE);
}

int	parser(const char *str, t_list *list, int *heredoc)
{
	t_element	*elm;
	t_token		*token;

	*heredoc = 0;
	if (lexer(str, list) == FT_FAILURE)
		return (print_quotes_error());
	if (list->size == 0)
		return (FT_SUCCESS);
	elm = list->head;
	if (check_start(elm))
		return (FT_FAILURE);
	if (is_parentheses_balanced(list) == 0)
		return (print_parentheses_error());
	while (elm)
	{
		token = (t_token *)elm->content;
		if (token->type == T_DLESS)
			(*heredoc)++;
		if (expect(elm, elm->next) == FT_FAILURE)
			return (FT_FAILURE);
		elm = elm->next;
	}
	if (*heredoc > 0)
		return (FT_REPROMPT);
	return (FT_SUCCESS);
}
