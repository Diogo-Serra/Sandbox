#include <stdio.h>
#include <stdlib.h>

void    last_word(char *source)
{
    int     i;
    int     j;
    int     g;
    int     len;
    char    *tmp;

    i = 0;
    while (source[i])
        i++;
    len = i + 1;
    tmp = malloc(len * sizeof(char));
    if (!tmp)
        return ;
    i--;
    while (source[i] == ' ')
        i--;
    while (source[i] != ' ')
        i--;
    i++;
    j = 0;
    while (source[i])
    {
        tmp[j] = source[i];
        i++;
        j++;
    }
    tmp[j++] = ' ';
    g = 0;
    while (j < len)
    {
        tmp[j] = source[g];
        j++;
        g++;
    }
    i = 0;
    j = 0;
    while (j < len)
    {
        source[j] = tmp[i];
        j++;
        i++;
    }
    source[j] = '\0';
    free(tmp);
}

int main(void)
{
    char    source[22] = "Hello World Test Exam";
    
    printf("Original: %s\n", source);
    last_word(source);
    printf("Last Word: %s\n", source);
    return (0);
}

