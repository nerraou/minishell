/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:11:17 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/10 10:01:05 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(char *value, int i)
{
	char	*after;
	char	*val;
	char	*befor;
	int 	j;

	befor = ft_substr(value, 0, i - 1);
	j = i;
	i--;
	while (value[j] && ft_isalnum(value[j]))
		j++;
	val = ft_substr(value, i, j - i);
	i = j + 1;
	j++;
	while (value[i])
		i++;
	after = ft_substr(value, j, i - j);
	printf()

}

void	dollar_handling(t_list *list, char **envp)
{
	(void) envp;
	t_element	*elm;
	t_token		*token;
	char		*buffer;
	int			i;

	buffer = NULL;
	elm = list->head;
	while (elm)
	{
		token = (t_token *)elm->content;
		i = 0;
		while (token->value[i] && token->value[i] != '$')
			i++;
		if (token->value[i] == '$' && token->value[i + 1])
		{
			i++;
			if (token->type == 2)
				return ;
			if (token->type == 1 || !token->type)
			{
				expand(token->value, i);
			}
		}

		elm = elm->next;
	}
}

void	expanding(t_list *list, char **envp)
{
	dollar_handling(list, envp);
}