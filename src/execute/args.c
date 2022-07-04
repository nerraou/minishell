/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:26:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/03 16:50:38 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_cmd(int mcr)
{
	return (mcr == T_LESS || mcr == T_GREAT || mcr == T_DGREAT || \
	mcr == T_DLESS || mcr == T_FILE || mcr == T_LIM || mcr == T_PIPE || \
	mcr == T_AND || mcr == T_OR || mcr == -1);
}

int	arg_count(t_element	*elm, t_element *l_cmd)
{
	t_token	*token;
	int		wc;

	wc = 0;
	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		if (token->type == 100)
			wc++;
		if (wc && !check_cmd(token->type))
		{
			if (token->type == T_D_STRING || token->type == T_S_STRING)
				wc += 1;
			else
				wc += wcount(token->value, ' ');
		}
		elm = elm->next;
	}
	return (wc);
}

void	spliting(t_cmd *cmd, char *args, int *i)
{
	char	**holder;
	int		j;

	holder = ft_split(args, ' ');
	if (holder)
	{
		j = 0;
		while (holder[j])
		{
			cmd->args[*i] = ft_strdup(holder[j]);
			(*i)++;
			free (holder[j]);
			j++;
		}
		free (holder);
	}
}

void	update_args(t_element *elm, t_element *l_cmd, t_cmd *cmd)
{
	t_token		*token;
	int			i;

	i = 1;
	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		if (!check_cmd(token->type) && token->type != 100)
		{
			if (wcount(token->value, ' ') == 1 || token->type == T_D_STRING || \
			token->type == T_S_STRING)
				cmd->args[i++] = ft_strdup(token->value);
			else
				spliting(cmd, token->value, &i);
		}
		elm = elm->next;
	}
}

void	prepear_execve_args(t_element *f_cmd, t_element *l_cmd, t_cmd *cmd)
{
	t_element	*elm;
	int			wc;

	wc = 0;
	if (cmd->executable == 1)
	{
		elm = f_cmd;
		wc = arg_count(elm, l_cmd);
		cmd->num_of_args = wc;
		cmd->args = (char **)malloc(sizeof(char *) * wc);
		cmd->args[0] = ft_strdup(cmd->cmd);
		cmd->args[wc - 1] = 0;
		elm = f_cmd;
		update_args(elm, l_cmd, cmd);
	}
}
