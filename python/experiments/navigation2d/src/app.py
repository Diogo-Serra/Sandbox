from .parser import parser
from .classes import Grid, Player, Navigation
from os import system


def run(argv: list[str]):

    grid_settings: tuple[int, int] = parser(argv)
    grid = Grid(*grid_settings)
    player = Player("Player1")
    navigation = Navigation(grid, player)

    while True:
        system("clear")
        navigation.render_navigation()
        choice = input("\nNavigation WASD or Q to quit > ")

        if choice == 'q':
            break
        else:
            navigation.navigate(choice)
