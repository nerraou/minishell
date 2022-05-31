/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:37:41 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/31 16:47:25 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strncpy(char *dest, const char *src, size_t n);
int ft_strcmp(const char *s1, const char *s2);
int ft_indexof(const char *str, int c);
int ft_atoi(const char *str);
int ft_isspace(const char *str);

size_t ft_strlen(const char *s);

#endif
