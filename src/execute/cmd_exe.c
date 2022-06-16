/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:25:43 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/16 09:47:45 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	cmd_execut(t_element *f_cmd, t_element *l_cmd, char **envp)
{
	t_element	*elm;
	t_token		*tok;

	expanding(f_cmd, l_cmd, envp);
	join_pieces(f_cmd, l_cmd);
	// io_files(f_cmd, l_cmd);
	elm = f_cmd;
	while (elm &&elm->prev != l_cmd)
	{
		tok = (t_token *)elm->content;
		printf("( %s )-( %d )-(%d)\n",tok->value, tok->type,tok->to_join);
		elm = elm->next;
	}
	// pipe_parse
	// fork_processes
}