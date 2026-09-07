from pydantic_settings import BaseSettings, SettingsConfigDict


class Settings(BaseSettings):
    model_config = SettingsConfigDict(env_file="Python/FastAPI/04ProjectStructure/.env")

    DB_CONNECTION: str

settings = Settings()