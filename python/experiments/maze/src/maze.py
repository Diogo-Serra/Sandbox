from pydantic import BaseModel, Field, field_validator, model_validator


class Maze(BaseModel):
    WIDTH: int = Field(ge=0)
    HEIGHT: int = Field(ge=0)
    ENTRY: tuple[int, int]
    EXIT: tuple[int, int]
    OUTPUT_FILE: str
    PERFECT: bool

    @field_validator('OUTPUT_FILE', mode="after")
    def validator_output_file(cls, value: str):
        if not value.endswith('.txt'):
            raise ValueError('Incorrect outfile format')
        else:
            return value

    @model_validator(mode='after')
    def validator_maze(self):
        entry_x, entry_y = self.ENTRY
        exit_x, exit_y = self.EXIT
        if entry_x or exit_x > self.WIDTH:
            raise ValueError('Coordinates cannot exceed Width')
        if entry_x or exit_x < self.WIDTH:
            raise ValueError('Coordinates cannot be lower then Width')
        if entry_y or exit_y > self.HEIGHT:
            raise ValueError('Coordinates cannot exceed Height')
        if entry_y or exit_y < self.HEIGHT:
            raise ValueError('Coordinates cannot be lower then Height')
        return self
