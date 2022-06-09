/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:49:48 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/09 11:18:25 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H
#include "list.h"
typedef struct s_token
{
	char *value;
	int type;
} t_token;

int set_d_string(const char *str, t_list *list);
int set_s_string(const char *str, t_list *list);
int ft_skip_spaces(const char *str);
int set_pipe(const char *str, t_list *list);
int set_great(const char *str, t_list *list);
int set_less(const char *str, t_list *list);
int set_dgreat(const char *str, t_list *list);
int set_dless(const char *str, t_list *list);
int set_word(const char *str, t_list *list);
int set_newline(const char *str, t_list *list);
t_token *ft_new_token(char *value, int type);
void lexer(const char *str, t_list *list);
int set_or(const char *str, t_list *list);
int set_and(const char *str, t_list *list);

#endif
