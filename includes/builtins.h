/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:44:20 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/22 11:54:55 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H

#include <errno.h>
#include "env.h"
#include "ft_stddef.h"
int echo(int ac, char *av[]);
int env(t_list *env_list);
int export(int ac, char *av[], t_list *env_list);
int unset(int ac, char *av[], t_list *env_list);
int pwd(void);
int cd(int ac, char *av[], t_list *env);
int is_var_name(const char *str, int len);

#endif