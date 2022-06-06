/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:28:29 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 15:09:00 by obelkhad         ###   ########.fr       */
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
#define T_LESS 3
#define T_GREAT 4
#define T_DLESS 5
#define T_DGREAT 6
#define T_PIPE 7
#define T_NEWLINE 8

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "list.h"
#include "lexer.h"
#include "get_next_line.h"

void	update_shlvl(char **envp);
char	*get_env_value(char	*env, char **envp, int *i);
void	history(char *cmd, char **envp);


#endif
