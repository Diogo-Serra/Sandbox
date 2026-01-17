#include <stdio.h>
#include <stdlib.h>

typedef struct s_phrase
{
    int     nwords;
    char    *first_word;
	char	*rest;
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

int	total_len(char *source)
{
	int i;

	i = 0;
	while (source[i])
		i++;
	return (i);
}

int word_len(char *source)
{
    int i;
	int j;

    i = 0;
	j = 0;
    while (source[i] == ' ')
	{
		i++;
	}
	while (source[i] != ' ')
	{
		i++;
		j++;
	}
    return (j);
}

char	*ft_rotate(char *source)
{
	int			i;
	int			j;
	t_phrase	*info;
	char		*rotate;

	info = ft_checkwords(source);
	if (info->nwords <= 1)
	{
		return (source);
	} else {
		i = word_len(source);
		info->first_word = malloc((i + 1) * sizeof(char));
		if (!info->first_word)
			return (NULL);
		i = 0;
		while (source[i] == ' ')
			i++;
		j = 0;
		while (source[i] != ' ')
			info->first_word[j++] = source[i++];
		info->first_word[j] = '\0';
	}
	while (source[i] == ' ')
		i++;
	j = 0;
	while (source[i])
	{
		j++;
		i++;
	}
	info->rest = malloc((j + 1) * sizeof(char));
	if (!info->rest)
		return (NULL);
	i = word_len(source);
	while (source[i] == ' ')
		i++;
	j = 0;
	while (source[i])
		info->rest[j++] = source[i++];
	info->rest[j] = ' ';
	i = word_len(info->first_word);
	j = total_len(info->rest);
	rotate = malloc((i + j + 1) * sizeof(char));
	if (!rotate)
		return (NULL);
	i = 0;
	j = 0;
	while (info->rest[i])
		rotate[j++] = info->rest[i++];
	i = 0;
	while (info->first_word[i])
		rotate[j++] = info->first_word[i++];
	rotate[j] = '\0';
	free(info);
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
		rotate = ft_rotate(argv[i++]);
		printf("%s\n", rotate);
	}
    return (0);
}
