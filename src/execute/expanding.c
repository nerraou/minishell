/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:40:40 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/05 15:30:16 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

void	to_expand(char *holder, char **expander, char **envp)
{
	char	*env;
	char	*minishell;

	env = ft_strjoin(holder, "=");
	*expander = get_env_value(env, envp);
	if (!ft_strncmp(*expander, holder, ft_strlen(holder)))
	{
		free(*expander);
		if (ft_isalnum(holder[0]) && holder[0] != '0')
			*expander = ft_strdup("");
		else if (holder[0] == '0')
		{
			minishell = ft_strdup("MINISH");
			free(env);
			env = ft_substr(holder, 1, ft_strlen(holder));
			*expander = ft_strjoin(minishell, env);
			free(minishell);
		}
		else
			*expander = ft_strjoin("$", holder);
	}
	free(env);
}

void	free_used_str(char **after, char **holder, char **befor, char **expandr)
{
	free(*expandr);
	free(*holder);
	free(*befor);
	free(*after);
}

void	expand(char **value, char **envp, int *i, int j)
{
	char	*after;
	char	*holder;
	char	*befor;
	char	*expander;

	update_befor(value, &befor, i);
	while ((*value)[j] && ft_isalnum((*value)[j + 1]))
		j++;
	update_after(value, &after, j);
	holder = ft_substr((*value), *i + 1, j - *i);
	*i = j - 1;
	if (!ft_strncmp(holder, "$", 1))
		expander = ft_itoa(getpid());
	else if (!ft_strncmp(holder, "?", 1))
		expander = ft_itoa(g_vars.exit_code);
	else
		to_expand(holder, &expander, envp);
	free(holder);
	if (*value)
		free(*value);
	holder = ft_strjoin(befor, expander);
	*value = ft_strjoin(holder, after);
	*i = ft_strlen(expander) + ft_strlen(befor) - 1;
	free_used_str(&after, &holder, &befor, &expander);
}

void	dollar(t_token *token, t_token *token_next, char **envp, int *i)
{
	if (token->value[*i] == '$' && token->value[*i + 1])
	{
		if (token->type == T_D_STRING || token->type == T_WORD || \
		(token->type == T_DLESS && token_next->type == T_WORD))
			expand(&token->value, envp, i, *i + 1);
	}
	(*i)++;
}

void	dollar_handling(t_element *f_cmd, t_element *l_cmd, char **envp)
{
	t_element	*elm;
	t_token		*token;
	t_token		*token_next;
	int			i;

	elm = f_cmd;
	while (elm && elm->prev != l_cmd)
	{
		i = 0;
		token = (t_token *)elm->content;
		if (elm->next)
			token_next = (t_token *)elm->next->content;
		check_tilda(&elm);
		while (token->value[i])
			dollar(token, token_next, envp, &i);
		elm = elm->next;
	}
	free_2_arr(envp);
}
