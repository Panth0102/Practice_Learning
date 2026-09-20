from fastapi import FastAPI
from src.utils.db import Base, engine
from src.tasks.router import task_routes
# from src.tasks.models import taskModel

Base.metadata.create_all(engine)

app = FastAPI(title="FastAPI Project Structure")
app.include_router(task_routes)