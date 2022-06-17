/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:38:07 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/17 17:11:15 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
#define ENV_H

#include "list.h"
#include "libft.h"

typedef struct s_env
{
	char *key;
	char *value;
	char *prepared;
} t_env;

t_list *init_env(char *env[]);

#endif