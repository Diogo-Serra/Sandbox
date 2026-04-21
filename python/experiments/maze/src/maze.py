from pydantic import BaseModel, Field, field_validator


class Maze(BaseModel):
    widht: int = Field(ge=0)
    height: int = Field(ge=0)
    start: tuple
    end: tuple
    output_file: str
    perfect: bool

    @field_validator('start', 'end', mode='after')
    def validator_start_end(cls, value: tuple):
        x, y = value
        if x < 0 or y < 0:
            raise ValueError("Error: only positive coordinates")
        return value

    @field_validator('output_file', mode="after")
    def validator_output_file(cls, value: str):
        if not value.endswith('.txt'):
            raise ValueError('Incorrect outfile format')
        else:
            return value
