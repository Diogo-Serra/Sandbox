#include <stdio.h>
#include <stdlib.h>

typedef struct s_phrase
{
    int     nwords;
    char    *first_word;
}   t_phrase;

t_phrase	*ft_checkwords(char *source)
{
    int			i;
    t_phrase	*phrase_info;

	if (!source)
		return (NULL);
	phrase_info = malloc(sizeof(t_phrase));
    i = 0;
    while (source[i])
    {
        if (source[i] != ' ' && (i == 0 || source[i - 1] == ' '))
        {
            if (!phrase_info->first_word)
				phrase_info->first_word = &source[i];
			phrase_info->nwords++;
        }
        i++;
    }
    return (phrase_info);
}

int word_len(char *source)
{
    int i;

    i = 0;
    while (source[i] != ' ')
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    int  i;
    
    if (argc <= 1)
        return (printf("\n"), 0);
    i = 0;
    while (i < argc)
        printf("%s\n", ft_rostring(argv[i++]));
    return (0);
}

