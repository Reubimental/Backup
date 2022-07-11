/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:54:46 by rkabzins          #+#    #+#             */
/*   Updated: 2022/03/04 00:54:51 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
void			*ft_memset(void *ptr, int c, size_t n);
void			ft_bzero(void *str, size_t n);
void			*ft_memchr(const void *ptr, int c, size_t num);
void			*ft_memcpy(void *dest, const void *src, size_t num);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
void			*ft_calloc(size_t n, size_t size);
char			*ft_strdup(const char *source);
char			*ft_substr(const char *source, unsigned int start, size_t finish);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strcpy(char *destination, const char *source);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_putstr_fd(char *str, int fd);
int				ft_toupper(unsigned char c);
int				ft_tolower(int c);
int				ft_isprint(int c);
int				ft_isdigit(char c);
int				ft_isascii(char c);
int				ft_isalpha(char c);
int				ft_isalnum(char c);
int				ft_islower(char c);
int				ft_isupper(char c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
long			ft_atol(const char *s);
int				ft_isspace(int c);
void			error_exit(void);
int				n_exists(unsigned int *stack, int stack_size, unsigned int check);
unsigned int	*error_check(int argc, char **argv);
int				stack_size(unsigned int *stack);
void			reverse_rotate(unsigned int *stack);
void			rotate(unsigned int *stack);
void			swap(unsigned int *stack);
void			ft_push(unsigned int *origin, unsigned int *destination);
void			pa(unsigned int *stack_a, unsigned int *stack_b, int command);
void			pb(unsigned int *stack_a, unsigned int *stack_b, int command);
void			ss(unsigned int *stack_a, unsigned int *stack_b);
void			rr(unsigned int *stack_a, unsigned int *stack_b);
void			rrr(unsigned int *stack_a, unsigned int *stack_b);
void			sa(unsigned int *stack_a, int command);
void			ra(unsigned int *stack_a, int command);
void			rra(unsigned int *stack_a, int command);
void			rrb(unsigned int *stack_b, int command);
void			rb(unsigned int *stack_b, int command);
void			sb(unsigned int *stack_b, int command);

#endif
