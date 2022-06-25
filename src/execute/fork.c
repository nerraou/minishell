/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:24:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/25 16:10:04 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_io(t_cmd *cmd, t_element **l_cmd)
{
	(void)cmd;
	t_token	*token;

	token = (t_token *)(*l_cmd)->content;
	if (token->type == T_PIPE)
	{
		token->type = -1;
		*l_cmd = (*l_cmd)->prev;
		// close(cmd->pipes[READ_END]);
		// dup2(cmd->pipes[WRITE_END] , STDOUT_FILENO);
		// close(cmd->pipes[WRITE_END]);
	}
}

int	fork_proccesses(t_element *f_cmd, t_element *l_cmd, char **envp, t_cmd *cmd)
{
	int		child;
	t_opr_logic	operators;


	child = fork();
	if (child == 0)
	{
		// pipe_io(cmd, &l_cmd);
		get_io(f_cmd, l_cmd);
		operators.f_cmd = f_cmd;
		operators.l_cmd = l_cmd;
		// check_parentheses(&operators);
		// t_element	*elm;
		// t_token		*token;
		// elm = operators.f_cmd;
		// while (elm && elm->prev != operators.l_cmd)
		// {
		// 	token = (t_token*)elm->content;
		// 	printf("[ %s ] . [ %d ]\n",token->value, token->type);
		// 	elm = elm->next;
		// }
		// printf("[++++++++++]\n\n");
		(void)envp;
		// if (executable_cmd(operators.f_cmd, envp, cmd))
		{
			prepear_execve_args(operators.f_cmd, operators.l_cmd, cmd);
			// if (!is_builtin(cmd))
			if (1)
			{
				// if (execve(cmd->args[0], cmd->args, envp) == -1)
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
	return (child);
}