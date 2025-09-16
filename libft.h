/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserra <diserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:57:01 by diserra           #+#    #+#             */
/*   Updated: 2025/09/17 00:51:56 by diserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

void	ft_putnbr(int nb);
void	bzero(void *s, size_t n);
void	*memset(void *s, int c, size_t n);
void	*memmove(void *dest, const void *src, size_t n);
void	*memcpy(void *dest, const void *src, size_t n);
void	*memccpy(void *dest, const void *src, int c, size_t n);
void	*memchr(const void *s, int c, size_t n);
int		memcmp(const void *s1, const void *s2, size_t n);
size_t	strlen(const char *s);

#endif /*LIBFT_H*/