from fastapi import APIRouter, Depends
from src.tasks import controller
from src.tasks.dtos import TaskSchema, TaskSchemaResponse
from src.utils.db import get_db
from fastapi import status
from typing import List
from sqlalchemy.orm import Session

task_routes = APIRouter(prefix='/task')

@task_routes.post('/create',response_model=TaskSchemaResponse ,status_code=status.HTTP_201_CREATED)
def create_task(body:TaskSchema, db:Session = Depends(get_db)):
    return controller.create_task(body, db)

@task_routes.get('/all',response_model=List(TaskSchema), status_code=status.HTTP_200_OK)
def get_all_task(db:Session = Depends(get_db)):
    return controller.get_all_task(db)

@task_routes.get('/one_task/{task_id}',response_model=TaskSchema, status_code=status.HTTP_200_OK)
def get_one_task(task_id:int, db:Session = Depends(get_db)):
    return controller.get_one_task(task_id, db)

@task_routes.put('/update/{task_id}',response_model=TaskSchemaResponse, status_code=status.HTTP_201_CREATED)
def update_task(task_id:int, body:TaskSchema, db:Session = Depends(get_db)):
    return controller.update_task(task_id, body, db)

@task_routes.put('/update_better/{task_id}',response_model=TaskSchemaResponse, status_code=status.HTTP_201_CREATED)
def update_better_task(task_id:int, body:TaskSchema, db:Session = Depends(get_db)):
    return controller.update_better_task(task_id, body, db)

@task_routes.delete('/delete/{task_id}', status_code=status.HTTP_204_NO_CONTENT)
def delete_task(task_id:int, db:Session = Depends(get_db)):
    return controller.delete_task(task_id, db)
    