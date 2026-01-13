#include <stdio.h>
#include <stdlib.h>

typedef struct s_person
{
	void		*data;
	struct s_person	*next;
}	t_person;

t_person	*add_person(void *data)
{
	t_person 	*new_person;
	char		*name;
	int		i;

	if (!data)
		return (NULL);
	new_person = malloc(sizeof(t_person));
	name = (char *)data;
	i = 0;
	while (name[i])
	{
		new_person->data[i] = name[i];
		i++;
	}
	new_person[i] = '\0';
	new_person->next = NULL;
	return (new_person);
}
int	main(void)
{
	t_person	*person1;
	person1 = add_person("Diogo");
	printf("%s\n", t_person->data);
	return (0);
}
