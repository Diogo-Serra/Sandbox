
class Map:

    def __init__(
        self,
        widht: int,
        height: int,
        start: tuple,
        end: tuple,
        output_file: str,
        perfect: bool,
    ) -> None:
        self.widht = widht
        self.height = height
        self.start = start
        self.end = end
        self.output_file = output_file
        self.perfect = perfect
