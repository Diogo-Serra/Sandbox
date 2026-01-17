/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rostring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:15:30 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/17 02:26:08 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_string
{
	int		total_len;
	int		total_words;
	int		size_firstword;
	char	*first_word;
	char	*rest;
}	t_string;

t_string	*string_info(char *source)
{
	t_string	*info;
	int			i;

	info = malloc(sizeof(t_string));
	if (!info)
		return (NULL);
	i = 0;
	while (source[i])
		i++;
	info->total_len = i;
	i = 0;
    while (source[i])
    {
        if (source[i] != ' ' && (i == 0 || source[i - 1] == ' '))
        {
            if (!info->first_word)
				info->first_word = &source[i];
			if (!info->rest && info->total_words >= 1)
				info->rest = &source[i];
			info->total_words++;
        }
        i++;
    }
	if (!info->first_word)
		return (free(info), NULL);
	i = 0;
	while (info->first_word[i] != ' ')
		i++;
	info->size_firstword = i;
	return (info);
}

char	*ft_rostring(char *source)
{
	t_string	*info;
	char		*rotate;
	int			i;
	int			j;

	if (!source || !*source)
		return (NULL);
	info = string_info(source);
	if (!info || info->total_words <= 1)
		return (source);
	rotate = malloc((info->total_len + 1) * sizeof(char));
	if (!rotate)
		return (NULL);
	i = 0;
	j = 0;
	while (info->rest[j])
		rotate[i++] = info->rest[j++];
	while (i > 0 && rotate[i - 1] == ' ')
		i--;
	rotate[i++] = ' ';
	j = 0;
	while (info->first_word[j] != ' ')
		rotate[i++] = info->first_word[j++];
	rotate[i] = '\0';
	return (rotate);
}

int main(int argc, char **argv)
{
    int  	i;
	char	*rotate;
    
    if (argc <= 1)
        return (printf("\n"), 0);
    i = 1;
    while (i < argc)
	{
		rotate = ft_rostring(argv[i++]);
		if (rotate)
			return (printf("%s\n", rotate), 0);
		else
			printf("\n");
	}
	return (0);
}
