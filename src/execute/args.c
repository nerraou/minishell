/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agrs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:26:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/23 18:26:45 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prepear_execve_args(t_element *f_cmd, t_element *l_cmd, t_cmd *cmd)
{
	t_element	*elm;
	t_token		*token;
	int			wc;
	int			i;

	wc = 0;
	if (cmd->executable == 1)
	{
		elm = f_cmd;
		while (elm && elm->prev != l_cmd)
		{
			token = (t_token *)elm->content;
			if (token->type == 100)
				wc++;
			if (wc && token->type != -1)
				wc++;
			elm = elm->next;
		}
		cmd->args = (char **)malloc(sizeof(char *) * wc);
		cmd->args[0] = ft_strdup(cmd->cmd);
		cmd->args[wc - 1] = 0;
		elm = f_cmd;
		wc = 0;
		i = 1;
		while (elm && elm->prev != l_cmd)
		{
			token = (t_token *)elm->content;
			if (wc && token->type != -1)
				cmd->args[i++] = ft_strdup(token->value);
			if (token->type == 100)
				wc++;
			elm = elm->next;
		}
	}
	if (cmd->executable == 2)
	{
		cmd->args = (char **)malloc(sizeof(char *) * 2);
		cmd->args[0] = ft_strdup("/bin/cat");
		cmd->args[1] = 0;
	}
}