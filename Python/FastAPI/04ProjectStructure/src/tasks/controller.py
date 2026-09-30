from src.tasks.dtos import TaskSchema
from sqlalchemy.orm import Session
from src.tasks.models import taskModel
from fastapi import HTTPException

def create_task(body: TaskSchema, db: Session):
    data = body.model_dump()
    task = taskModel(title = data['title'], description = data['description'], is_completed = data['is_completed'])

    db.add(task)
    db.commit()
    db.refresh(task)
    return {"status": "Task created successfully!", "data": task}


#To create a new task, we will create a function called create_task that takes in a TaskSchema object and a database session. We will then create a new taskModel object using the data from the TaskSchema object, add it to the database session, commit the changes, and return a success message along with the newly created task.
def get_all_task(db: Session):
    task = db.query(taskModel).all()
    return {"status": "Task fetched successfully!", "data": task}


#To fetch specific task, we will create a function called get_task that takes in a task id and a database session. We will then query the database for the task with the given id and return it along with a success message.
def get_one_task(task_id : int, db: Session):
    task = db.query(taskModel).get(task_id)
    if not task:
        raise HTTPException(status_code=404, detail="Task not found")
    return {"status": "Task fetched successfully!", "data": task}