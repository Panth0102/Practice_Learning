from pydantic import BaseModel

class DdosForProduct(BaseModel):
    id: int
    title: str
    description: str = ' '
    price: float = 0