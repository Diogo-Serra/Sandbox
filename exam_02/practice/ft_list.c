#include <stdio.h>
#include <stdlib.h>

typedef struct s_person
{
    char            name[50];
    int             age;
    struct s_person *next;
}   t_person;

void    add_front(t_person **head, t_person *new_node)
{
    if (!new_node)
        return ;
    new_node->next = *head;
    *head = new_node;
}

ssize_t lst_size(t_person **head)
{
    t_person    *current;
    ssize_t     count;

    if (!head)
        return (0);
    count = 0;
    current = *head;
    while (current)
    {
        count++;
        current = current->next;
    }
    return (count);
}

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
    t_person    *head;
    ssize_t     size;

    head = NULL;
    person1 = new_person("Diogo", 35);
    printf("Hello World\n%s - %d\n", person1->name, person1->age);
    add_front(&head, person1);
    size = lst_size(&head);
    printf("%zu\n", size);
    free(person1);
    return (0);
}
