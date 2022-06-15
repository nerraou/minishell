/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:25:43 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/15 16:42:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	joining(t_element *gathering, t_element *part)
{
	t_token		*token_gathering;
	t_token		*token_part;
	char		*holder;

	token_gathering = (t_token *)gathering->content;
	token_part = (t_token *)part->content;
	holder = ft_strjoin(token_gathering->value, token_part->value);
	free(token_gathering->value);
	token_gathering->value = holder;
}

void	join_pieces(t_element *f_cmd, t_element *l_cmd)
{
	t_token		*token;
	t_element	*elm;
	t_element	*gathering;
	int			join;

	join = 1;
	elm = f_cmd;
	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		if (token->to_join && join)
		{
			gathering = elm;
			join = 0;
		}
		else if (token->to_join && !join)
		{
			joining(gathering, elm);
			token->type = -1;
		}
		else
			join = 1;
		elm = elm->next;
	}
}

void	cmd_execut(t_element *f_cmd, t_element *l_cmd, char **envp)
{
	t_element	*elm;
	t_token		*tok;
	elm = f_cmd;

	expanding(f_cmd, l_cmd, envp);
	join_pieces(f_cmd, l_cmd);
	
	while (elm &&elm->prev != l_cmd)
	{
		tok = (t_token *)elm->content;
		printf("( %s )-( %d )-(%d)\n",tok->value, tok->type,tok->to_join);
		elm = elm->next;
	}

	// pipe_parse
	// fork_processes
}