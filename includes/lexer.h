/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:49:48 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/19 09:34:30 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "libft.h"
#include "ft_stddef.h"

typedef struct s_token
{
	char *value;
	int type;
	int to_join;
} t_token;

#define T_WORD 0
#define T_D_STRING 1
#define T_S_SRRING 2
#define T_LESS 3
#define T_GREAT 4
#define T_DGREAT 5
#define T_DLESS 6
#define T_PIPE 7
#define T_NEWLINE 8
#define T_OR 9
#define T_AND 10
#define T_L_PARENTH 12 // (
#define T_R_PARENTH 13 // )

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
int set_l_parenth(const char *str, t_list *list);
int set_r_parenth(const char *str, t_list *list);
int is_joinable(char c);

#endif
