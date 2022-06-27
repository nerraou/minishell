/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:24:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/27 19:58:40 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_io(t_cmd *cmd, t_element **l_cmd)
{
	t_token	*token;

	token = (t_token *)(*l_cmd)->content;
	if (token->type == T_PIPE)
	{
		token->type = -1;
		*l_cmd = (*l_cmd)->prev;
		close(cmd->pipes[READ_END]);
		dup2(cmd->pipes[WRITE_END] , STDOUT_FILENO);
		close(cmd->pipes[WRITE_END]);
	}
}

int	is_wildcard(t_element *elm)
{
	int		i;
	int		exist;
	t_token	*token;

	i = 0;
	exist = -1;
	token = (t_token *)elm->content;
	while (token->value[i])
	{
		if (token->value[i] == '*')
		{
			exist = i;
			break;
		}
		i++;
	}
	return (exist);
}

bool wildcard_match(char *file, char *pattern, int n, int m)
{
	int		i;
	int		j;
    bool	lookup[n + 1][m + 1];

	ft_memset(lookup, false, sizeof(lookup));
    lookup[0][0] = true;
	j = 1;
	while (j <= m)
	{
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];
		j++;
	}
	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= m)
		{
     		if (file[i - 1] == pattern[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1];
           	else  if (pattern[j - 1] == '*')
                lookup[i][j]= lookup[i][j - 1] || lookup[i - 1][j];
			j++;
		}
		i++;
	}
    return lookup[n][m];
}

void	wildcard_expand(t_element *f_cmd, t_element *l_cmd)
{
	t_element	*elm;
	t_token		*token;
	struct dirent *dire;
	// char		*str[];
	char		*file;
	char		*holder;
	char		*all_files;

	elm = f_cmd;
	all_files = NULL;
	holder = NULL;
	while (elm && elm->prev != l_cmd)
	{
		if (is_wildcard(elm) > -1)
		{
			token = (t_token *)elm->content;
			DIR *dir = opendir(".");
			if (dir)
			{
				while ((dire = readdir(dir)) != NULL)
				{
					if (wildcard_match(dire->d_name, token->value, ft_strlen(dire->d_name), ft_strlen(token->value)))
					{
						if (all_files)
						{
							holder = ft_strdup(all_files);
							free(all_files);
						}
						file = ft_strjoin(ft_strdup(dire->d_name) , " ");
						all_files = ft_strjoin(holder, file);
						free(holder);
						free(file);
						printf("> %s\n", all_files);
					}
				}
				closedir(dir);
			}
		}
		elm = elm->next;
	}
}

int	fork_proccesses(t_element *f_cmd, t_element *l_cmd, char **envp, t_cmd *cmd)
{
	int		child;
	t_opr_logic	operators;

	child = fork();
	if (child == 0)
	{
		pipe_io(cmd, &l_cmd);
		get_io(f_cmd, l_cmd);
		operators.f_cmd = f_cmd;
		operators.l_cmd = l_cmd;
		check_parentheses(&operators);

		executable_cmd(operators.f_cmd, envp, cmd);
		wildcard_expand(f_cmd, l_cmd);

		// t_element *elm;
		// t_token *token;
		// elm = f_cmd;
		// while (elm)
		// {
		// 	token = (t_token *)elm->content;
		// 	printf("[%s] [%d]\n",token->value, token->type);
		// 	elm = elm->next;
		// }
		prepear_execve_args(operators.f_cmd, operators.l_cmd, cmd);
		// if (!is_builtin(cmd))
		if (1)
		{
			if (execve(cmd->args[0], cmd->args, envp) == -1)
			{
				/* CMD ERROR*/
				/*free cmd*/
				/*close opend file*/
				/*free pipe && close*/
				/*exit code*/
				/*exit()*/
				// perror("execve");
				// exit (1);
			}
		}
		else
		{
			printf("is buildin cmd \n");
		}
	}
	return (child);
}