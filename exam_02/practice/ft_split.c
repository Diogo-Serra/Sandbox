/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 01:46:49 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/24 02:03:31 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int count_words(char *s)
{
    int i;
    int count;

    i = 0;
    while (s[i])
    {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
                count++;
        i++;
    }
    return (count);
}

int main(int ac, char **av)
{
    int words;

    if (ac != 2)
        return (printf("\n"), 0);
    words = count_words(av[1]);
    printf("%d\n", words);
    return (0);
}
