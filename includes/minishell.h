/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:28:29 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/14 09:20:50 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

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
#include "execute.h"
#include "get_next_line.h"

void update_shlvl(char **envp);
char *get_env_value(char *env, char **envp, int *i);
void history(char *cmd, char **envp);
void prompt(char *_prompt, char **envp);
void execut(t_list *list);
#endif
