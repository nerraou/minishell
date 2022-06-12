/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:25:43 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/12 16:44:42 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_execut(t_element *f_cmd, t_element *l_cmd, char **envp)
{
	t_element *elm;
	t_token *token;

	elm = f_cmd;

	expanding(f_cmd, l_cmd, envp);

	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
        printf("[ %s ][%d]\n",token->value, token->type);
        elm = elm->next;
	}
	printf("--------------------------\n");

	// pipe_parse
	// fork_processes
}