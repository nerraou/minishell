/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:07:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/09 07:49:08 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	execut(t_list *cmd, char **envp)
// {
// 	t_element *cmds;

// 	cmd = expand_cmd(cmd, envp);
// 	cmds = elem_new(cmd);
// 	pipe_parse(cmd, &cmds);
// 	fork_processes(cmds, envp);
// 	free(cmd);
// 	check_empty_line();
// }