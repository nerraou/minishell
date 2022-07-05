/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:22:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/05 16:49:04 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include "ft_stddef.h"
# include <readline/readline.h>

int		expect(t_element *cur_elem, t_element *next_elem);
int		is_word_string(t_element *cur_elem);
int		is_redirection(t_element *cur_elem);
int		is_separator(t_element *cur_elem);
int		is_dless(t_element *cur_elem);
int		symbol_expect(t_element *next_elem);
int		dless_expect(t_element *next_elem);
int		separator_expect(t_element *next_elem);
int		check_start(t_element *elm);
int		parser(const char *str, t_list *list, int *heredoc);
int		is_parentheses_balanced(t_list *list);
int		lparenthesis_expect(t_element *next_elm);
int		rparenthesis_expect(t_element *next_elm);
int		is_l_parenthesis(t_element *cur_elm);
int		is_r_parenthesis(t_element *cur_elm);
int		wordstring_expect(t_element *next_elm);

void	move_heredoc_content(t_list *list, t_list *heredoc_list);
void	print_syntax_error(t_element *elem);

t_list	*heredoc(int heredoc_num, t_list *list);

#endif
