/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:37:41 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/06 12:12:18 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strncpy(char *dest, const char *src, size_t n);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_indexof(const char *str, int c);
int ft_atoi(const char *str);
int ft_isspace(int c);
char *ft_strdup(const char *s);
void *ft_memset(void *s, int c, size_t n);
void *ft_malloc(size_t size);
size_t ft_strlen(const char *s);
char	*ft_itoa(int n);
void	*ft_memcpy(void	*dst, const void	*src, size_t	n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);

#endif
