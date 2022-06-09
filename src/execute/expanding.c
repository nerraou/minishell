/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:11:17 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/09 15:25:08 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollar(t_list *list, char **envp)
{
	t_element	*temp;
	t_token		*token;
	char		*buffer;
	int			i;

	i = 0;
	temp = list->head;
	while (temp)
	{
		token = (t_token *)temp->content;
		if (token->type == 2)
			return ;
		if (token->type == 1 || !token->type)
		{
			while (token->value[i] && token->value[i] != '$')
				i++;
			if (token->value[i] && i > 0)
			{
				
			}
		}
		i = 0;
		temp = temp->next;
	}
}

void	expanding(t_list *list)
{
}