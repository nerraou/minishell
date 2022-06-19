/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:29:04 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/18 15:29:23 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	free_pipes(int	**pipes, int size)
{
	while (size >= 0)
	{
		free(pipes[size]);
		size--;
	}
	free(pipes);
}

int	n_of_pipes(t_element *f_cmd, t_element *l_cmd)
{
	t_element	*elm;
	t_token		*token;
	int	pipes;

	pipes = 0;
	elm = f_cmd;
	token = (t_token *)elm->content;
	while (elm && elm->prev != l_cmd)
	{
		if (token->type == T_PIPE)
			pipes++;
		elm = elm->next;
	}
	return (pipes);
}

void	pipes_creation(t_element *f_cmd, t_element *l_cmd, int n_pipe)
{
	int i;
	int	**pipes_r_w;

	i = 0;
	if (n_pipe > 0)
		pipes_r_w = (int **)malloc(sizeof(int *) * n_pipe);
	while (i < n_pipe)
	{
		pipes_r_w[i] = (int *)malloc(sizeof(int) * 2);
		if (pipe(pipes_r_w[i]) == -1)
		{
			free_pipes(pipes_r_w, i);
			perror("minish: pipe");
		}
		i++;
	}
}