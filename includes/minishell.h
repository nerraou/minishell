/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:28:29 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/30 18:12:36 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#define FT_SUCCESS 0
#define FT_FAILURE 1

#define FT_STDIN 0
#define FT_STDOUT 1
#define FT_STDERR 2

#define T_WORD 0
#define T_D_STRING 1
#define T_S_SRRING 2
#define T_SEMICOLON 3
#define T_LESS 4
#define T_GREAT 5
#define T_DLESS 6
#define T_DGREAT 7
#define T_PIPE 8

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

typedef struct s_token
{
	char *value;
	int type;
} t_token;

#endif
