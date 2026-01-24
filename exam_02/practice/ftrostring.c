/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrostring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 23:04:20 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/24 00:31:25 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int count_words(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if ((s[i] != ' ') && (i == 0 || s[i - 1] == ' '))
            count++;
        i++;
    }
    return (count);
}

int main(int ac, char **av)
{
    int j;
    int end;
    int start;
    int words;

    if (ac <= 1)
        return (write(1, "\n", 1), 0);
    if (ac == 2)
    {
        words = count_words(av[1]);
        if (words <= 1)
            return (printf("%s\n", av[1]), 0);
        j = 0;
        while (av[1][j] == ' ' || av[1][j] == '\t')
            j++;
        start = j;
        while (av[1][j] != ' ' && av[1][j] != '\t')
            j++;
        end = j - 1;
        while (av[1][j] == ' ' || av[1][j] == '\t')
            j++;
        while (av[1][j])
            write(1, &av[1][j++], 1);
        write(1, " ", 1);
        while (start <= end)
            write(1, &av[1][start++], 1);
   }
    return (0);
}

