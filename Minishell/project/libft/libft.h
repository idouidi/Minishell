/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:35:53 by othabchi          #+#    #+#             */
/*   Updated: 2021/07/12 16:30:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# define BUFFER_SIZE 1024

void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy(void *str1, const void *str2, int c, size_t n);
void			*ft_memchr(const void*s, int c, size_t n);
void			ft_swap(char *a, char *b);
void			showtab(char **s);
char			*ft_leak(char *str);
char			**ft_leak_2(char **str);
char			***ft_leak_3(char ***s);
char			**ft_strdup_2(char **str);
int				get_next_line(int fd, char **line);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
size_t			ft_nbrlen(int nbr);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strnew(char **str);
char			*ft_epur(char *s);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strnstr(char const *haystack,
					const char *needle, size_t len);
long			ft_atoi(const char *str);
char			*ft_itoa(int n);
void			*ft_calloc(size_t nitems, size_t size);
void			ft_putchar(char c);
void			ft_putnbr(int c);
void			ft_putnbr_fd(int c, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putstr(char *str);
void			ft_putendl_fd(char *s, int fd);
char			*ft_strdup(const char *str);
char			*ft_strndup(const char *str, size_t n);
char			*ft_substr(char const *s, int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_memalloc(size_t n);
char			**ft_split(char *s, char *set);
int				ft_strcmp(char *s1, char *s2);
#endif
