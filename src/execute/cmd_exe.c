/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:25:43 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/20 18:44:10 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path_from_env(char *envp[])
{
	char	**path;
	char	*path_line;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (0);
	path_line = (char *)malloc(sizeof(char) * (ft_strlen(envp[i]) + 4));
	ft_strlcpy(path_line, envp[i] + 5, ft_strlen(envp[i]) - 4);
	path = ft_split(path_line, ':');
	free (path_line);
	if (!path)
		return (0);
	i = 0;
	while (path[i])
	{
		path_line = ft_strdup(path[i]);
		free (path[i]);
		path[i] = ft_strjoin_two_str(path_line, "/");
		free (path_line);
		i++;
	}
	return (path);
}

int	executable_cmd(t_element *f_cmd, t_element *l_cmd, char **envp, t_cmd *cmd)
{
	char		**path;
	t_token		*token;
	t_element	*elm;
	int			i;

	i = 0;
	elm = f_cmd;
	token = (t_token *)f_cmd->content;
	if (token->type >= T_LESS && token <= T_DGREAT)
		elm = f_cmd->next->next;
	if (token->type == T_DLESS)
		return ;
	token = (t_token *)elm->content;
	path = get_path_from_env(envp);
	if (!path)
	{
		/*free*/
		exit (1);
	}
	while (path[i])
	{
		cmd->cmd_name = token->value;
		cmd->cmd = ft_strjoin(path[i], token->value);
		if (access(cmd->cmd, X_OK))
			break ;
		free (cmd->cmd);
		free (cmd->cmd_name);
		i++;
	}
	if (path[i])
		cmd->executable = 1;
	else
	{
		cmd->executable = 0;
		write(2, cmd->cmd, ft_strlen(cmd->cmd));
		write(2, ":command not found\n", ft_strlen(":command not found\n"));
	}
	return (cmd->executable);
}

int	how_many_element(t_element *f_cmd, t_element *l_cmd)
{
	t_element	*elm;
	int			counter;

	counter = 0;
	elm = f_cmd;
	while (elm && elm->prev != l_cmd)
	{
		counter++;
		elm = elm->next;
	}
	return (counter);
}

char	**prepear_execve_args(t_element *f_cmd, t_element *l_cmd, t_cmd	*cmd)
{
	char		**args;
	t_element	*elm;
	t_token		*token;
	int			wc;
	int			i;

	i = 1;
	elm = f_cmd;
	elm = elm->next;
	wc = how_many_element(f_cmd, l_cmd);
	args = (char **)malloc(sizeof(char *) * (wc + 2));
	args[0] = ft_strdup(cmd->cmd);
	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		args[i] = ft_strdup(token->value);
		elm = elm->next;
		i++;
	}
	args[wc + 1] = 0;
	return (args);
}

void	close_pipes(t_cmd *cmd)
{
	int	i;

	if (cmd->id == 0)
	{
		i = cmd->id + 1;
		while (i < cmd->n_of_pipes)
		{
			close(cmd->pipes[i][READ_END]);
			close(cmd->pipes[i][WRITE_END]);
			i++;
		}
	}
	else if (cmd->id > 0 && cmd->id < cmd->n_of_pipes)
	{
		i = 0;
		while (i < cmd->id - 1)
		{
			close(cmd->pipes[i][READ_END]);
			close(cmd->pipes[i][WRITE_END]);
			i++;
		}
		close(cmd->pipes[cmd->id - 1][WRITE_END]);
		i = cmd->id + 1;
		while (i < cmd->n_of_pipes)
		{
			close(cmd->pipes[i][READ_END]);
			close(cmd->pipes[i][WRITE_END]);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < cmd->id - 1)
		{
			close(cmd->pipes[i][READ_END]);
			close(cmd->pipes[i][WRITE_END]);
			i++;
		}
		close(cmd->pipes[cmd->id - 1][WRITE_END]);
	}
}

void	fork_proccesses(t_element *f_cmd, t_element *l_cmd, char **envp, t_cmd *cmd)
{
	int		child;
	t_token	*token_first;
	t_token	*token_last;

	child = fork();
	if (child == 0)
	{
		/* INPUT */
		token_first = (t_token *)l_cmd->content;
		token_last = (t_token *)f_cmd->content;
		if (cmd->id == 0 && token_last->type == T_PIPE)
		{
			close(cmd->pipes[cmd->id][READ_END]);
			dup2(cmd->pipes[cmd->id][WRITE_END], STDOUT_FILENO);
			close(cmd->pipes[cmd->id][WRITE_END]);
			close_pipes(cmd);
		}

		
		if (token->type == T_PIPE)
		{
			
			/*output to pipe*/
		}
		else
		{
			/*output to STDOUT*/
		}
		get_io(f_cmd, l_cmd);
		if (executable_cmd(f_cmd, l_cmd, envp, cmd))
		{
			cmd->args = prepear_execve_args(f_cmd, l_cmd, cmd);
			if (!is_builtin(cmd))
			{
				
			}
		}
		else
		{
			/* CMD ERROR*/
			/*free cmd*/
			/*close opend file*/
			/*free pipe && close*/
			/*exit code*/
			/*exit()*/
		}

	}
}

void	cmd_execut(t_element *f_cmd, t_element *l_cmd, char **envp,  t_list *heredoc_list)
{
	t_element	*pipes;
	t_token		*token;
	int			n_cmd;
	t_cmd		*cmd;
	int			cmd_num;

	cmd->id = 0;
	expanding(f_cmd, l_cmd, envp);
	join_pieces(f_cmd, l_cmd);
	cmd->n_of_pipes = n_of_pipes(f_cmd, l_cmd);
	cmd->pipes = pipes_creation(f_cmd, l_cmd);
	pipes = f_cmd;
	while (pipes && pipes->prev != l_cmd)
	{
		token = (t_token *)pipes->content;
		while (token->type != T_PIPE || pipes != l_cmd)
		{
			pipes = pipes->next;
			token = (t_token *)pipes->content;
		}
		fork_proccesses(f_cmd, pipes, envp, cmd);
		cmd->id++;
		f_cmd = pipes->next;
		pipes = f_cmd;
	}


	// t_element	*elm;
	// t_token		*tok;
	// elm = f_cmd;
	// while (elm &&elm->prev != l_cmd)
	// {
	// 	tok = (t_token *)elm->content;
	// 	printf("( %s )-( %d )-(%d)\n",tok->value, tok->type,tok->to_join);
	// 	elm = elm->next;
	// }
	// printf("--------------------\n");
}