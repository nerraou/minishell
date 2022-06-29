/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
/*   expander: Invalid date        by 2.fr>             #+#    #+#             */
/*   Updated: 2022/06/28 19:48:05 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	is_special(char c)
{
	return (c == '?' || c == '$');
}

void	expand(char **value, char **envp, int *i)
{
	char	*befor;
	char	*expander;
	char	*after;
	char	*holder;
	int		j;

	if (*i > 0)
		befor = ft_substr((*value), 0, *i);
	else
		befor = NULL;
	j = *i + 1;
	while (((*value)[j] && ft_isalnum((*value)[j + 1])))
		j++;
	expander = ft_substr((*value), *i + 1, j - *i);
	printf(">>v %s\n",expander);
	if (!ft_strncmp(expander, "$", 1))
		after = ft_itoa(getpid());
	else if (!ft_strncmp(expander, "?", 1))
		after = ft_itoa(g_vars.exit_code);
	else
	{
		holder = ft_strjoin(expander, "=");
		after = get_env_value(holder, envp);
		free(holder);
	}

	free(expander);
	expander = ft_strdup(after);
	free(after);
	*i = j + 1;
	while ((*value)[j])
		j++;
	if (j - *i > 0)
		after = ft_substr((*value), *i, j - *i);
	else
		after = NULL;
	if (*value)
		free(*value);
	*value = ft_strjoin(ft_strjoin(befor, expander), after);
	free(befor);
	free(after);
	free(expander);
}

void	dollar(t_token *token, char **envp, int *i, t_token *s_str)
{
	if (token->value[*i] == '$' && token->value[*i + 1])
	{
		if (token->type == T_D_STRING || token->type == T_WORD || \
		(token->type == T_DLESS && s_str->type != T_S_SRRING))
			expand(&token->value, envp, i);
		(*i)--;
		(*i)--;
		printf("{ %s } = %d = %c\n\n",token->value + *i, *i, token->value[*i]);
	}
	(*i)++;
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
			dollar(token, envp, &i, s_str);
		elm = elm->next;
	}
	free_2_arr(envp);
}
