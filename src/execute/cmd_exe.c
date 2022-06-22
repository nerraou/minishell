/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:25:43 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/22 19:17:35 by obelkhad         ###   ########.fr       */
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
		path[i] = ft_strjoin(path_line, "/");
		free (path_line);
		i++;
	}
	return (path);
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

void	prepear_execve_args(t_element *f_cmd, t_element *l_cmd, t_cmd	*cmd)
{
	t_element	*elm;
	t_token		*token;
	int			wc;
	int			i;

	wc = 0;
	if (cmd->executable == 1)
	{
		elm = f_cmd;
		while (elm && elm->prev != l_cmd)
		{
			token = (t_token *)elm->content;
			if (token->type == 100)
				wc++;
			if (wc && token->type != -1)
				wc++;
			elm = elm->next;
		}
		cmd->args = (char **)malloc(sizeof(char *) * wc);
		cmd->args[0] = ft_strdup(cmd->cmd);
		cmd->args[wc - 1] = 0;
		elm = f_cmd;
		wc = 0;
		i = 1;
		while (elm && elm->prev != l_cmd)
		{
			token = (t_token *)elm->content;
			if (wc && token->type != -1)
				cmd->args[i++] = ft_strdup(token->value);
			if (token->type == 100)
				wc++;
			elm = elm->next;
		}
	}
}

void	close_pipes(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->n_of_pipes)
	{
		if (!(i == cmd->id || i == cmd->id - 1))
		{
			close(cmd->pipes[i][READ_END]);
			close(cmd->pipes[i][WRITE_END]);
		}
		i++;
	}
}

void	pipe_io(t_cmd *cmd, t_element *l_cmd)
{
	t_token	*token;

	token = (t_token *)l_cmd->content;
	if (cmd->id == 0 && token->type == T_PIPE)
	{
		token->type = -1;
		close_pipes(cmd);
		close(cmd->pipes[cmd->id][READ_END]);
		dup2(cmd->pipes[cmd->id][WRITE_END], STDOUT_FILENO);
		close(cmd->pipes[cmd->id][WRITE_END]);
	}
	if (cmd->id > 0 && token->type == T_PIPE)
	{
		token->type = -1;
		close_pipes(cmd);
		close(cmd->pipes[cmd->id - 1][WRITE_END]);
		dup2(cmd->pipes[cmd->id - 1][READ_END], STDIN_FILENO);
		close(cmd->pipes[cmd->id - 1][READ_END]);
		close(cmd->pipes[cmd->id][READ_END]);
		dup2(cmd->pipes[cmd->id][WRITE_END], STDOUT_FILENO);
		close(cmd->pipes[cmd->id][WRITE_END]);
	}
	if (cmd->id > 0 && token->type != T_PIPE)
	{
		close_pipes(cmd);
		close(cmd->pipes[cmd->id - 1][WRITE_END]);
		dup2(cmd->pipes[cmd->id - 1][READ_END], STDIN_FILENO);
		close(cmd->pipes[cmd->id - 1][READ_END]);
	}
}

int	executable_cmd(t_element *f_cmd, char **envp, t_cmd *cmd)
{
	t_element	*elm;
	t_token		*token;
	char		**path;
	int			i;

	elm = f_cmd;
	cmd->executable = 2;
	token = (t_token *)elm->content;
	while (elm && token->type == -1)
	{
		elm = elm->next;
		if (elm)
			token = (t_token *)elm->content;
	}
	if (elm)
	{
		token->type = 100;
		cmd->cmd_name = ft_strdup(token->value);
		path = get_path_from_env(envp);
		if (!path)
		{
			/*free*/
			exit (1);
		}
		i = 0;
		while (path[i])
		{
			cmd->cmd = ft_strjoin(path[i], cmd->cmd_name);
			if (!access(cmd->cmd, X_OK))
				break ;
			i++;
		}
		if (path[i])
			cmd->executable = 1;
		else
		{
			cmd->executable = 0;
			write(2, cmd->cmd_name, ft_strlen(cmd->cmd_name));
			write(2, " :command not found\n", ft_strlen(" :command not found\n"));
		}
	}
	return (cmd->executable);
}

void	fork_proccesses(t_element *f_cmd, t_element *l_cmd, char **envp, t_cmd *cmd)
{
	int		child;


	// int	t[2];

	// t[0] = dup(STDIN_FILENO);
	// t[1] = dup(STDOUT_FILENO);

	child = fork();
	if (child == 0)
	{
	// dup2(t[0], STDIN_FILENO);
	// dup2(t[1], STDOUT_FILENO);
	pipe_io(cmd, l_cmd);
	get_io(f_cmd, l_cmd);
	if (executable_cmd(f_cmd, envp, cmd))
	{

	// t_token	*tok;
	// t_element *elm;
	// elm = f_cmd;
	// printf("\n");
	// while (elm &&elm->prev != l_cmd)
	// {
	// 	tok = (t_token *)elm->content;
	// 	printf("( %s )-( %d )\n",tok->value, tok->type);
	// 	elm = elm->next;
	// }

		prepear_execve_args(f_cmd, l_cmd, cmd);
		{
			
			// printf("id = %d \n",cmd->id);
			// printf("cmd = %s \n",cmd->cmd);
			// printf("name = %s \n",cmd->cmd_name);
			// printf("pipe = %d \n",cmd->n_of_pipes);
			// printf("ex? = %d \n",cmd->executable);
			// int i = 0;
			// while (cmd->args[i])
			// {
			// 	printf("arg[%d] = %s \n",i, cmd->args[i]);
			// 	i++;
			// }
			// printf("--------------------\n");
		}


		// if (!is_builtin(cmd))
		if (1)
		{
			if (execve(cmd->args[0], cmd->args, envp) == -1)
			{
				// printf("--------------------\n");
				/* CMD ERROR*/
				/*free cmd*/
				/*close opend file*/
				/*free pipe && close*/
				/*exit code*/
				/*exit()*/
				perror("execve");
				exit (1);
			}
		}
		else
		{
			printf("is buildin cmd \n");
		}
	}
	// else
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

void	cmd_execut(t_element *f_cmd, t_element *l_cmd, char **envp)
{
	t_element	*pipes;
	t_token		*token;
	t_cmd		*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
	{
		/*free*/
		/*exit (1)*/
	}
	cmd->cmd_name = NULL;
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->pipes = NULL;
	cmd->id = 0;
	expanding(f_cmd, l_cmd, envp);
	join_pieces(f_cmd, l_cmd);
	cmd->n_of_pipes = n_of_pipes(f_cmd, l_cmd);
	cmd->pipes = pipes_creation(cmd);
	pipes = f_cmd;
	while (pipes && pipes->prev != l_cmd)
	{
		token = (t_token *)pipes->content;
		while (token->type != T_PIPE && pipes != l_cmd)
		{
			pipes = pipes->next;
			token = (t_token *)pipes->content;
		}
		fork_proccesses(f_cmd, pipes, envp, cmd);
		waitpid(-1, NULL, 0);
		cmd->id++;
		pipes = pipes->next;
		f_cmd = pipes;
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