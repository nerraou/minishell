/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:44:20 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/18 18:19:44 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H

#include "env.h"
#include "ft_stddef.h"
int echo(int ac, char *av[]);
int env(t_list *env_list);
int export(int ac, char *av[], t_list *env_list);
int is_valid_var_name(const char *str, int len);

#endif