from fastapi import FastAPI, Request
from mockData import products
app = FastAPI()

@app.get("/")       # Default Home route
def home():
    return "Hello User"

@app.get("/products")
def product():
    return products      

# --------------------------------------------------------------------------------------------

# Path Parameters

# http://127.0.0.1:8000/product/1  path parameters


#Fixed compulsory values
@app.get("/product/{id}")
def get_one_product(id: int):
    
    for i in products:
        if i["id"] == id:
            return i

    return "Product not found"

# ----------------------------------------------

#Fixed compulsory values
@app.get("/product/{id}/{title}")
def get_one_product2(id: int, title: str):
    
    for i in products:
        if i["id"] == id and i["title"] == title:
            return i

    return "Product not found"

# http://127.0.0.1:8000/product/1/mac

# --------------------------------------------------------------------------------------------------

# Query Parameters

# http://127.0.0.1:8000/product/?id=3&title=Product%203&description=Description%20of%20Product%203&price=5.99 

# Usually used for fixed values
@app.get("/product")
def greet_user(name: str, age: int): 
    return f"Hello {name}, you are {age} years old"


# ----------------------------------------------

#Mutliple values with no fix number of values
@app.get("/product2")
def greet_user2(request:Request):
    query_params = (dict(request.query_params))     # Shows all data recieved in query
    return query_params


# name=p&age=2