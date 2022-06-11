/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:29:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/11 15:58:12 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
#define EXECUTE_H

typedef struct s_opr_logic
{
	t_element	*f_cmd;
	t_element	*opr_cmd;
	t_element	*l_cmd;
	int			operator;
} t_opr_logic;

void	execut(t_list *list, char **envp);
void	expanding(t_element *f_cmd, t_element *l_cmd, char **envp);
char	*get_env_value(char	*env, char **envp);
int		check_env(char	*vrb, char **envp);
#endif