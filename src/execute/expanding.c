/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:11:17 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/10 12:00:46 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(char *value, char **envp, int i)
{
	char	*after;
	char	*val;
	char	*befor;

	int 	j;
	(void)envp;

	if (i - 1 > 0)
		befor = ft_substr(value, 0, i - 1);
	else
		befor = NULL;
	j = i;
	while (value[j] && ft_isalnum(value[j]))
		j++;
	val = ft_substr(value, i , j - i);
	i = j;
	while (value[j])
		j++;
	if (j - i > 0)
		after = ft_substr(value, i, j - i);
	else
		after = NULL;
	printf ("val = %s\n",ft_strjoin(val, "="));
	{
		printf ("befor = %s\n",befor);
		printf ("val = %s\n",val);
		printf ("after = %s\n",after);
	}
	// result = ft_strjoin(ft_strjoin(befor, get_env_value(ft_strjoin(val, "="), envp, NULL)), after);
	// printf ("result = %s\n",result);
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
			if (token->type == T_S_SRRING)
				return ;
			if (token->type == T_D_STRING || token->type == T_WORD)
				expand(token->value, envp, i);
		}

		elm = elm->next;
	}
}

void	expanding(t_list *list, char **envp)
{
	dollar_handling(list, envp);
}