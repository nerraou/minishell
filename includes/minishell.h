/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:28:29 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/04 12:37:36 by obelkhad         ###   ########.fr       */
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
#include <curses.h>
#include <signal.h>
#include <dirent.h>
#include <stdbool.h>
#include <term.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "list.h"
#include "lexer.h"
#include "execute.h"
#include "builtins.h"
#include "env.h"
#include "get_next_line.h"

typedef struct s_global_vars
{
	int		exit_code;
	int		heredoc;
	char	*tilda;
}	t_global_vars;

t_global_vars	g_vars;

void	history(char *cmd, char **envp);
void	prompt(char *_prompt, char **envp, t_list *env_list, int in);

#endif
