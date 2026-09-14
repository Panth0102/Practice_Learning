from sqlalchemy import Integer, Boolean, Column, String
from src.utils.db import Base


class taskModel(Base):
    __tablename__ = "user_task"

    id = Column(Integer, primary_key=True, index=True)
    title = Column(String, nullable=False)
    description = Column(String, nullable=False)
    is_completed = Column(Boolean, default=False)

