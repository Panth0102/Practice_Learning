from src.tasks.dtos import TaskSchema
from sqlalchemy.orm import Session
from src.tasks.models import taskModel

def create_task(body: TaskSchema, db: Session):
    data = body.model_dump()
    task = taskModel(title = data['title'], description = data['description'], is_completed = data['is_completed'])

    db.add(task)
    db.commit()
    db.refresh(task)
    return {"status": "Task created successfully!", "data": task}