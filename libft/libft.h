/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:40:05 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/04 20:03:11 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);
int		ft_atoi(const char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putnbr(int nb);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstadd_front(t_list **lst, t_list *new);
size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		t_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*join_strings(int count, ...);
int		count_equal(int count, int target, ...);
double	avg_int(int count, ...);
int		total(int n, ...);
int		max(int n, ...);
char	*ft_strjoin_free(char *s1, char const *s2);

#endif /*LIBFT_H*/