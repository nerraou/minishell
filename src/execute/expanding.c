/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:40:40 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/02 18:01:00 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "minishell.h"

void	update_befor(char **value, char **befor, int *i)
{
	if(*i > 0)
		*befor = ft_substr((*value), 0, *i);
	else
		*befor = NULL;
}

void	update_after(char **value, char **after, int j)
{
	int	end;

	end = j;
	while ((*value)[end])
		end++;
	if (end - j > 0)
		*after = ft_substr((*value), j + 1, end - j);
	else
		*after = NULL;
}

void	to_expand(char *holder, char **expander, char **envp)
{
	char	*env;
	char	*minishell;

	env = ft_strjoin(holder, "=");
	*expander = get_env_value(env, envp);
	if(!ft_strncmp(*expander, holder, ft_strlen(holder)))
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

void	expand(char **value, char **envp, int *i)
{
	char	*after;
	char	*holder;
	char	*befor;
	char	*expander;
	int		j;

	j = *i + 1;
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
	free(expander);
	free(holder);
	free(befor);
	free(after);
}

void	dollar(t_token *token, char **envp, int *i, t_token *s_str)
{
	if (token->value[*i] == '$' && token->value[*i + 1])
	{
		if (token->type == T_D_STRING || token->type == T_WORD || (token->type == T_DLESS && s_str->type != T_S_STRING))
			expand(&token->value, envp, i);
	}
	(*i)++;
}

void check_tilda(t_element **elm, char **envp)
{
	t_token		*token;
	token = (t_token *)(*elm)->content;
	if (!ft_strncmp(token->value, "~", ft_strlen(token->value)))
	{
		free(token->value);
		token->value = get_env_value("HOME=" ,envp);
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
		check_tilda(&elm, envp);
		if (elm->next)
			s_str = (t_token *)elm->next->content;
		while (token->value[i])
			dollar(token, envp, &i, s_str);
		elm = elm->next;
	}
	free_2_arr(envp);
}
