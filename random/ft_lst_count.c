#include <stdio.h>
#include <stdlib.h>

typedef struct  s_player
{
    char            name[20];
    int             age;
    struct s_player *next;
}   t_player;

int     list_size(t_player *head)
{
    t_player    *current;
    int         count;

    current = head;
    count = 0;
    while (current)
    {
        count++;
        current = current->next;
    }
    return (count);
}

void    add_front(t_player **head, t_player *new_node)
{
    new_node->next = *head;
    *head = new_node;
}

t_player    *add_player(char *name, int age)
{
    t_player    *new_player;
    int         i;

    if (!name || !age)
        return (NULL);
    new_player = malloc(sizeof(t_player));
    if (!new_player)
        return (NULL);
    i = 0;
    while (name[i])
    {
        new_player->name[i] = name[i];
        i++;
    }
    new_player->name[i] = '\0';
    new_player->age = age;
    new_player->next = NULL;
    return (new_player);
}

int main(void)
{
    t_player    *player1;
    t_player    *player2;
    player1 = add_player("Diogo", 35);
    player2 = add_player("Di", 30);
    printf("%s - %d\n", player1->name, player1->age);
    printf("%s - %d\n", player2->name, player2->age);
    free(player1);
    free(player2);
    return (0);
}
