#include <stdio.h>
#include <stdlib.h>

typedef struct s_player
{
    ssize_t         id;
    char            name[20];
    struct s_player *next;
}   t_player;

void    add_front(t_player **head, t_player *new_node)
{
    new_node->next = *head;
    *head = new_node;
}

ssize_t    lst_size(t_player *head)
{
    t_player    *current;
    ssize_t     count;

    count = 0;
    current = head;
    while (current)
    {
        count++;
        current = current->next;
    }
    return (count);
}

t_player    *add_player(ssize_t id, char *name)
{
    t_player    *new_player;
    ssize_t i;

    if (!id || !name)
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
    new_player->id = id;
    new_player->next = NULL;
    return (new_player);
}

int main(void)
{
    t_player    *head;
    t_player    *player1;
    t_player    *player2;
    ssize_t     size;

    player1 = add_player(1, "Diogo");
    player2 = add_player(2, "Di");
    printf("%zu\n%s\n", player1->id, player1->name);
    printf("%zu\n%s\n", player2->id, player2->name);
    add_front(&head, player1);
    add_front(&head, player2);
    size = lst_size(head);
    printf("size: %zu\n", size);
    free(player1);
    free(player2);
    return (0);
}
