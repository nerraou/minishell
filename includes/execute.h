/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:29:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/23 18:34:13 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
#define EXECUTE_H

# define READ_END 0
# define WRITE_END 1

typedef struct s_opr_logic
{
	t_element	*f_cmd;
	t_element	*opr_cmd;
	t_element	*l_cmd;
	int			operator;
	t_element	*parent_r;
	t_element	*parent_l;
} t_opr_logic;

typedef struct s_cmd
{
	int		id;
	char	*cmd;
	char	*cmd_name;
	char	**args;
	int		pipes[2];
	int		next_is_pipes;
	int		executable;
} t_cmd;

void	execut(t_list *list, char **envp);
void	expanding(t_element *f_cmd, t_element *l_cmd, char **envp);
char	*get_env_value(char	*env, char **envp);
int		check_env(char	*vrb, char **envp);
void	execute(t_element *f_cmd, t_element *l_cmd, char **envp, int in);
void	priority(t_element *f_cmd, t_element *l_cmd, char **envp, int in);
void	divide_by_last_operator(t_opr_logic *opertor);
void	join_pieces(t_element *f_cmd, t_element *l_cmd);
int		**pipes_creation(t_cmd *cmd);
int		n_of_pipes(t_element *f_cmd, t_element *l_cmd);
void	free_pipes(int	**pipes, int size);
void	get_io(t_element *f_cmd, t_element *l_cmd);
int		fork_proccesses(t_element *f_cmd, t_element *l_cmd, char **envp, t_cmd *cmd);
void	prepear_execve_args(t_element *f_cmd, t_element *l_cmd, t_cmd *cmd);
int		executable_cmd(t_element *f_cmd, char **envp, t_cmd *cmd);
#endif