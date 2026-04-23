try:
    from pydantic import ( # noqa
        BaseModel,
        Field,
        field_validator,
        model_validator,
        ValidationError)
except ImportError:
    print("Error importing modules")
    exit(1)


class Maze(BaseModel):
    WIDTH: int = Field(ge=3, le=40)
    HEIGHT: int = Field(ge=3, le=40)
    ENTRY: tuple[int, int]
    EXIT: tuple[int, int]
    OUTPUT_FILE: str
    PERFECT: bool

    @field_validator('OUTPUT_FILE', mode="after")
    def validator_output_file(cls, value: str):
        if not value.endswith('.txt'):
            raise ValueError('Incorrect output_file format')
        else:
            return value

    @model_validator(mode='after')
    def validator_maze(self):
        entry_x, entry_y = self.ENTRY
        exit_x, exit_y = self.EXIT
        if entry_x >= self.WIDTH or exit_x >= self.WIDTH:
            raise ValueError('Coordinates cannot exceed Width')
        if entry_x < 0 or exit_x < 0:
            raise ValueError('Coordinates cannot be negative')
        if entry_y >= self.HEIGHT or exit_y >= self.HEIGHT:
            raise ValueError('Coordinates cannot exceed Height')
        if entry_y < 0 or exit_y < 0:
            raise ValueError('Coordinates cannot be negative')
        if self.ENTRY == self.EXIT:
            raise ValueError('Entry and Exit cannot be the same cell')
        return self

    def __str__(self) -> str:
        return (f"Width: {self.WIDTH}\nHeight: {self.HEIGHT}\n"
                f"Entry: {self.ENTRY}\nExit: {self.EXIT}\n"
                f"Output_file: {self.OUTPUT_FILE}\n"
                f"Perfect: {self.PERFECT}")
