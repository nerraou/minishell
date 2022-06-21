/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:38:07 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/21 13:56:20 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
#define ENV_H

#include "list.h"
#include "libft.h"
#include "ft_stddef.h"
#include <stdlib.h>

typedef struct s_env
{
	char *key;
	char *value;
	char *prepared;
} t_env;

t_list *init_env(char *env[]);
t_env *new_env(const char *env_value);
void del_env(t_env *env);
t_element *ft_getenv(t_list *env, const char *key);
int ft_setenv(t_list *env_list, t_env *env);
int ft_unsetenv(t_list *env_list, const char *key);
void sort_array(char **arr, int size);
char **list_to_array(t_list *env_list);

#endif
