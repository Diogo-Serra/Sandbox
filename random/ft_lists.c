#include <stdio.h>
#include <stdlib.h>

typedef struct s_player
{
    ssize_t         id;
    char            name[20];
    struct s_player *next;
}   t_player;

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
    t_player    *player1;

    player1 = add_player(1, "Diogo");
    printf("%zu\n%s\n", player1->id, player1->name);
    free(player1);
    return (0);
}
