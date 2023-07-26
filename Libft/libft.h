/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:56:38 by lamici            #+#    #+#             */
/*   Updated: 2023/06/30 15:27:03 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *str1, const void *str2, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strrchr(const char *str, int c);
int		ft_tolower(int ch);
int		ft_toupper(int ch);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t num, size_t dim);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//printf
int		ft_char(int c);
int		ft_digit(int n);
int		ft_hexd(unsigned int n, char format);
int		ft_path(unsigned long int n);
int		ft_printf(const char *str, ...);
int		ft_string(char *str);
int		ft_unsigned(unsigned int n);
int		ft_matrix(char **mat);
//printf_fd
int		ft_char_fd(int fd, int c);
int		ft_digit_fd(int fd, int n);
int		ft_hexd_fd(int fd, unsigned int n, char format);
int		ft_path_fd(int fd, unsigned long int n);
int		ft_printf_fd(int fd, const char *str, ...);
int		ft_string_fd(int fd, char *str);
int		ft_unsigned_fd(int fd, unsigned int n);
int		ft_matrix_fd(int fd, char **mat);

char	*get_next_line(int fd);
int		ft_matlen(char **mat);
void	ft_kill_matrix(char **mat);
int		ft_strcmp(char *str1, char *str2);

#endif