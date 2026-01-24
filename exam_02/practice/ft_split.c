/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 01:46:49 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/24 03:34:39 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char **s)
{
    int     i;
    char    *dup;

    i = 0;
    while ((*s)[i] && (*s)[i] != ' ')
        i++;
    dup = malloc((i + 1) * sizeof(char));
    if (!dup)
        return (NULL);
    i = 0;
    while (**s && **s != ' ')
    {
        dup[i++] = **s;
        (*s)++;
    }
    dup[i] = '\0';
    return (dup);
}

int count_words(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
                count++;
        i++;
    }
    return (count);
}

void    free_heap(char **source)
{
    int i;

    i = 0;
    while (source[i])
        free(source[i++]);
    free(source);
}

char    **ft_split(char *source)
{
    char    **split;
    int     nwords;
    int     i;

    nwords = count_words(source);
    if (nwords < 1)
        return (NULL);
    split = (char **)malloc((nwords + 1) * sizeof(char **));
    if (!split)
        return (NULL);
    i = 0;
    while (i < nwords)
    {
        while (*source && *source == ' ')
            source++;
        split[i] = ft_strdup(&source);
        if (!split[i])
            return (free_heap(split), NULL);
        i++;
    }
    split[i] = NULL;
    return (split);
}

int main(int ac, char **av)
{
    int     i;
    char    **split;
    
    if (ac != 2)
        return (printf("\n"), 0);
    split = ft_split(av[1]);
    if (!split)
        return (1);
    i = 0;
    while (split[i])
        printf("%s\n", split[i++]);
    free_heap(split);
    return (0);
}

