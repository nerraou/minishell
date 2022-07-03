/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:37:41 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/02 15:46:12 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

// #define FT_MAX_LONG ÷

char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strncpy(char *dest, const char *src, size_t n);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_strcmp(const char *s1, const char *s2);
int ft_indexof(const char *str, int c);
int ft_atoi(const char *str);
long ft_atol(const char *str);
int ft_isspace(int c);
char *ft_strdup(const char *s);
void *ft_memset(void *s, int c, size_t n);
void *ft_malloc(size_t size);
size_t ft_strlen(const char *s);
char *ft_itoa(int n);
void *ft_memcpy(void *dst, const void *src, size_t n);
char *ft_strjoin(char const *s1, char const *s2);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
void ft_putendl_fd(char *s, int fd);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
char **ft_split(char const *s, char c);
int	wcount(char const *s, char c);
int is_long(const char *str);
int	ft_tolower(int c);

#endif
