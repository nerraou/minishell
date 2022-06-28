/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:29:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 18:07:59 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
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
}	t_opr_logic;

typedef struct s_cmd
{
	int		id;
	char	*cmd;
	char	*cmd_name;
	char	**args;
	int		pipes[2];
	int		next_is_pipes;
	int		executable;
	int		num_of_args;
}	t_cmd;

typedef struct s_wild
{
	char	*file;
	char	*holder;
	char	*all_matches;
}	t_wild;

void	execut(t_list *list, char **envp);
void	dollar_handling(t_element *f_cmd, t_element *l_cmd, char **envp);
char	*get_env_value(char	*env, char **envp);
int		check_env(char	*vrb, char **envp);
void	execute(t_element *f_cmd, t_element *l_cmd, t_list *env_list, int in);
void	priority(t_element *f_cmd, t_element *l_cmd, t_list *env_list, int in);
void	divide_by_last_operator(t_opr_logic *opertor);
void	join_pieces(t_element *f_cmd, t_element *l_cmd);
int		**pipes_creation(t_cmd *cmd);
int		n_of_pipes(t_element *f_cmd, t_element *l_cmd);
void	free_pipes(int	**pipes, int size);
void	get_io(t_element *f_cmd, t_element *l_cmd);
int		fork_proc(t_element *f_cmd, t_element *l_cmd, t_list *env, t_cmd **cmd);
void	prepear_execve_args(t_element *f_cmd, t_element *l_cmd, t_cmd *cmd);
void	executable_cmd(t_element *f_cmd, char **envp, t_cmd *cmd);
int		check_parentheses(t_opr_logic *operators);
void	sig_handel(int sig);
void	ctr_d(void);
int		empty_prompt(char *cmd);
void	wildcard_expand(t_element *f_cmd, t_element *l_cmd);
void	open_file_write(char *outfile, int mode);
void	open_file_read(char	*infile);
void	init_wild(t_wild *match);
void	update_element(t_element *elm, t_wild *match, int i);
int		is_wildcard(t_element *elm);
void	free_2_arr(char **env_arr);
void	pipe_out(t_cmd *cmd);
void	get_exit_code(int *status);
void	last_child(t_cmd *cmd, int child);
void	creat_pipe(t_cmd **cmd, t_token *token);
void	detect_pipe(t_element **pipes, t_element *l_cmd);
int		is_builtin(char	*cmd);
void	exe_builtin(int built, t_cmd *cmd, t_list *env_);
int		free_lookup(bool **lookup, int n, int m);
#endif