from pydantic import BaseModel
class TaskSchema(BaseModel):
    title: str | None = None
    description: str | None = None
    is_completed: bool | None = None