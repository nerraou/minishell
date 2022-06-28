/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:11:17 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 17:59:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(char **value, char **envp, int i)
{
	char	*after;
	char	*env;
	char	*befor;
	int		j;

	if (i - 1 > 0)
		befor = ft_substr((*value), 0, i - 1);
	else
		befor = NULL;
	j = i;
	while ((*value)[j] && ft_isalnum((*value)[j]))
		j++;
	env = ft_substr((*value), i, j - i);
	i = j;
	while ((*value)[j])
		j++;
	if (j - i > 0)
		after = ft_substr((*value), i, j - i);
	else
		after = NULL;
	*value = ft_strjoin(ft_strjoin(befor, get_env_value(ft_strjoin(env, "="), \
	envp)), after);
	free(befor);
	free(after);
	free(env);
}

void	dollar(t_token *token, char **envp, int *i, t_token *s_str)
{
	if (token->value[*i] == '$' && token->value[*i + 1])
	{
		(*i)++;
		if (token->type == T_D_STRING || token->type == T_WORD || \
		(token->type == T_DLESS && s_str->type != T_S_SRRING))
			expand(&token->value, envp, *i);
	}
}

void	dollar_handling(t_element *f_cmd, t_element *l_cmd, char **envp)
{
	t_element	*elm;
	t_token		*token;
	t_token		*s_str;
	int			i;

	elm = f_cmd;
	while (elm && elm->prev != l_cmd)
	{
		i = 0;
		token = (t_token *)elm->content;
		if (elm->next)
			s_str = (t_token *)elm->next->content;
		while (token->value[i])
		{
			dollar(token, envp, &i, s_str);
			i++;
		}
		elm = elm->next;
	}
	free_2_arr(envp);
}
