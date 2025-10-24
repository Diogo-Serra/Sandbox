/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:40:05 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/24 14:45:44 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

int		ft_atoi(const char *s);
int		memcmp(const void *s1, const void *s2, size_t n);
char	*strcpy(char *dest, const char *src);
char	*strdup(const char *s);
void	bzero(void *s, size_t n);
void	*memccpy(void *dest, const void *src, int c, size_t n);
void	*memchr(const void *s, int c, size_t n);
void	*memcpy(void *dest, const void *src, size_t n);
void	*memmove(void *dest, const void *src, size_t n);
void	*memset(void *s, int c, size_t n);
void	ft_putnbr(int nb);
size_t	strlen(const char *s);

#endif /*LIBFT_H*/