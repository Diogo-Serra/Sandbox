/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:26:30 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/01 20:21:35 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/* =========================================================*/
/* get_next_line                                            */
/* =========================================================*/
char	*get_next_line(int fd);
char	*clean_buffer(char *buffer);
size_t	ft_strllen(const char *source);
char	*ft_strchr(const char *s, int c);
char	*ft_strnjoin(char *line, char const *buffer);

#endif
