#include <stdio.h>
#include <stdlib.h>

typedef struct s_person
{
    char            name[50];
    int             age;
    struct s_person *next;
}   t_person;

t_person    *new_person(char *name, int age)
{
    t_person    *new_person;
    int         i;

    if (!name || !age)
        return (NULL);
    new_person = malloc(sizeof(t_person));
    if (!new_person)
        return (NULL);
    i = 0;
    while (name[i])
    {
        new_person->name[i] = name[i];
        i++;
    }
    new_person->name[i] = '\0';
    new_person->age = age;
    new_person->next = NULL;
    return (new_person);
}

int main(void)
{
    t_person    *person1;

    person1 = new_person("Diogo", 35);
    printf("Hello World\n%s - %d\n", person1->name, person1->age);
    return (0);
}
