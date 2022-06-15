/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:22:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/15 17:14:23 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ft_stddef.h"
#include <readline/readline.h>

int expect(t_element *cur_elem, t_element *next_elem);
int is_word_string(t_element *cur_elem);
int is_redirection(t_element *cur_elem);
int is_separator(t_element *cur_elem);
int is_dless(t_element *cur_elem);
int symbol_expect(t_element *next_elem);
int dless_expect(t_element *next_elem);
int separator_expect(t_element *next_elem);
void print_syntax_error(t_element *elem);
int check_start(t_element *elm);
int parser(const char *str, t_list *list, int *heredoc);
t_list *heredoc(int *heredoc_num, t_list *list);

#endif
