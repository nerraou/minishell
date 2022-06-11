/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:07:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/11 17:04:07 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_execut(t_element *f_cmd, t_element *l_cmd, char **envp)
{
	(void)envp;
	// (void)f_cmd;
	// (void)l_cmd;

	t_element *elm;
	t_token *token;

	elm = f_cmd;
	while (elm != l_cmd->next)
    {
        token = (t_token *)elm->content;
        printf("[ %s ][%d]\n",token->value, token->type);
        elm = elm->next;
    }
	printf("MMMMMMMMMMMM\n");

	// expanding(f_cmd, l_cmd, envp);

	// cmd = expand_cmd(cmd, envp);

	// cmds = elem_new(cmd);
	// pipe_parse(cmd, &cmds);
	// fork_processes(cmds, envp);
	// free(cmd);
	// check_empty_line();

}

void	divide_by_last_operator(t_element *f_cmd, t_element *l_cmd,t_opr_logic *opertor)
{
	t_token		*token;
	int			parentheses;

	parentheses = 1;
	opertor->operator = 0;
	opertor->f_cmd = f_cmd;
	opertor->l_cmd = l_cmd;
	opertor->opr_cmd = l_cmd;
	while (opertor->opr_cmd != opertor->f_cmd)
	{
		token = (t_token *)opertor->opr_cmd->content;
		if (token->type == T_R_PARENTH)  // )
			parentheses = 0;
		if (token->type == T_L_PARENTH)  // (
			parentheses = 1;
		if (parentheses)
		{
			if (token->type == T_AND || token->type == T_OR)
			{
				// token = (t_token *)opertor->f_cmd->content;
				// printf("f = %s\n",token->value);
				// token = (t_token *)opertor->opr_cmd->content;
				// printf("o = %s\n",token->value);
				// token = (t_token *)opertor->l_cmd->content;
				// printf("l = %s\n",token->value);

				opertor->operator = token->type;
				token->type = -1;
				// opertor->opr_cmd = opertor->opr_cmd->prev;
				break ;
			}
		}
		opertor->opr_cmd = opertor->opr_cmd->prev;
	}
}

void	priority_handling(t_element *f_cmd, t_element *l_cmd, char **envp)
{
	t_opr_logic	operators;
	// t_token		*token;

	divide_by_last_operator(f_cmd, l_cmd, &operators);
	if (operators.opr_cmd == operators.f_cmd)
	{
		// printf("LOL\n");
		// token = (t_token *)operators.f_cmd->content;
		// printf("f = %s\n",token->value);
		// token = (t_token *)operators.opr_cmd->content;
		// printf("o = %s\n",token->value);
		// token = (t_token *)operators.l_cmd->content;
		// printf("l = %s\n",token->value);
		cmd_execut(operators.f_cmd, operators.l_cmd, envp);

	}
	else
		priority_handling(operators.f_cmd, operators.opr_cmd->prev, envp);
	if (operators.operator == T_OR) // && cmd not success
		priority_handling(operators.opr_cmd->next, operators.l_cmd, envp);
	if (operators.operator == T_AND) // && cmd success
		priority_handling(operators.opr_cmd->next, operators.l_cmd, envp);
}

void	execut(t_list *list, char **envp)
{
	t_element	*elm;

	elm = list->head;

	priority_handling(list->head, list->tail, envp);
    // t_token *token;
    // int i;

    // i = 0;
	// while (elm)
    // {
    //     token = (t_token *)elm->content;
    //     printf("[ %s ][%d]\n",token->value, token->type);
    //     elm = elm->next;
    // }
}