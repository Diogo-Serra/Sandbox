/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:33:29 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/24 17:05:20 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char **source)
{
    int     i;
    char    *dup;
    i = 0;
    while ((*source)[i] && (*source)[i] != ' ')
        i++;
    dup = malloc((i + 1) * sizeof(char));
    if (!dup)
        return (NULL);
    i = 0;
    while (**source && **source != ' ')
    {
        dup[i++] = **source;
        (*source)++;
    }
    dup[i] = '\0';
    return (dup);
}

int count_words(char *source)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (source[i])
    {
        if (source[i] != ' ' && (i == 0 || source[i - 1] == ' '))
            count++;
        i++;
    }
    return (count);
}

void    free_heap(char **split)
{
    int i;

    i = 0;
    while(split[i])
        free(split[i++]);
    free(split);
}

char    **ft_split(char *source)
{
    char    **split;
    int     nwords;
    int     i;

    nwords = count_words(source);
    if (nwords < 1)
        return (NULL);
    split = malloc((nwords + 1) * sizeof(char **));
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

int main(int ac, char ** av)
{
    char    **split;
    int     i;

    if (ac != 2)
        return (printf("\n"), 0);
    split = ft_split(av[1]);
    i = 0;
    while (split[i])
        printf("%s\n", split[i++]);
    free_heap(split);
    return (0);
}
