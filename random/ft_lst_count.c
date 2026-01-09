#include <stdio.h>
#include <stdlib.h>

typedef struct  s_player
{
    char            name[20];
    int             age;
    struct s_player *next;
}   t_player;

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
    new_player->age = age;
    new_player->next = NULL;
    return (new_player);
}

int main(void)
{
    t_player    *player1;
    player1 = add_player("Diogo", 35);
    printf("%s - %d\n", player1->name, player1->age);
    free(player1);
    return (0);
}
