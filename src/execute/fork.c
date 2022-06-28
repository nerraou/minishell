/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:24:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/28 13:47:32 by obelkhad         ###   ########.fr       */
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
		dup2(cmd->pipes[WRITE_END], STDOUT_FILENO);
		close(cmd->pipes[WRITE_END]);
	}
}

// int	is_builtin(char	*cmd)
// {
// 	int	check;

// 	check = 0;
// 	if (cmd)
// 	{
// 		if (!ft_strncmp(cmd, "cd", 2))
// 			check = 1;
// 		if (!ft_strncmp(cmd, "echo", 4))
// 			check = 2;
// 		if (!ft_strncmp(cmd, "pwd", 3))
// 			check = 3;
// 		if (!ft_strncmp(cmd, "export", 6))
// 			check = 4;
// 		if (!ft_strncmp(cmd, "unset", 5))
// 			check = 5;
// 		if (!ft_strncmp(cmd, "env", 3))
// 			check = 6;
// 		if (!ft_strncmp(cmd, "exit", 3))
// 			check = 7;

// 	}
// 	return (check);
// }

int	fork_proccesses(t_element *f_cmd, t_element *l_cmd, char **envp, t_cmd *cmd)
{
	int			child;
	t_opr_logic	operators;
	// int			built;

	child = fork();
	if (child == 0)
	{
		pipe_io(cmd, &l_cmd);
		get_io(f_cmd, l_cmd);
		operators.f_cmd = f_cmd;
		operators.l_cmd = l_cmd;
		check_parentheses(&operators);
		executable_cmd(operators.f_cmd, envp, cmd);
		// t_element *elm;
		// t_token *to;
		// elm = f_cmd;
		// while (elm && elm->prev != l_cmd)
		// {
		// 	to = (t_token*)elm->content;
		// 	printf("(%s) = (%d)\n",to->value,to->type);
		// 	elm = elm->next;
		// }
		wildcard_expand(f_cmd, l_cmd);
		prepear_execve_args(operators.f_cmd, operators.l_cmd, cmd);
		// built = is_builtin(cmd->cmd_name);
		// if (!built)
		{
			// int i = 0;
			// while (cmd->args[i])
			// {
			// 	printf("%s\n",cmd->args[i]);
			// 	i++;
			// }

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
		// else
		{
			//free
		}
	}
	return (child);
}
