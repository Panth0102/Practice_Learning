# fastapi dev Python/FastAPI/01BasicAPI.PY   
# How to access server

from fastapi import FastAPI

app = FastAPI()

@app.get("/")       # Default Home route
def home():
    return "Hello User"



# http://127.0.0.1:8000/connect
@app.get("/connect")       # Default Home route
def connect():
    return "Connect us at xyz@abc.com"


# To kill a server, use the command: lsof -i :8000 & kill -9 <PID> (where <PID> is the process ID of the server) or ctrl + c