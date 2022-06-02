/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:49:48 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/01 17:22:11 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

int set_d_string(const char *str, t_list *list);
int set_s_string(const char *str, t_list *list);
int ft_skip_spaces(const char *str);
int set_pipe(const char *str, t_list *list);
int set_great(const char *str, t_list *list);
int set_less(const char *str, t_list *list);
int set_dgreat(const char *str, t_list *list);
int set_dless(const char *str, t_list *list);
int set_word(const char *str, t_list *list);

#endif
