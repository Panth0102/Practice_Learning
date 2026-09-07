from fastapi import FastAPI, Request
from mockData import products
from ddosForProduct import DdosForProduct
app = FastAPI()

#CRUD Operations
    # Using postman to test the API

# Get: Client recieve's something from Server (Read something) R
@app.get("/products")
def product():
    return products

@app.get("/product/{id}")
def get_one_product(id: int):
    
    for i in products:
        if i["id"] == id:
            return i

    return "Product not found"

# Post: Client send's something to Server (Add something) C
@app.post("/create_product")
def add_product(product: DdosForProduct):
    product = product.model_dump()  # Used to convert into dictionary

    products.append(product)
    print(product)
    return {"message": "Product added successfully", "data": products}

# Passing data through Body Method
# {
#     "id": 4,
#     "title": "macbook",
#     "description": "Description of Product 3",
#     "price": 12.99
# }

# Put: Client send's something to Server and Server updates it (Update something) U
@app.put("/update_product/{id}")
def update_product(id: int, product: DdosForProduct):
    for i in products:
        if i["id"] == id:
            i.update(product.model_dump())
            return {"message": "Product updated successfully", "data": products}
    return {"message": "Product not found"}

# Delete: Client send's something to Server and Server deletes it (Delete something) D
@app.delete("/delete_product/{id}")
def delete_product(id: int):
    for i in products:
        if i["id"] == id:
            products.remove(i)
            return {"message": "Product deleted successfully", "data": products}
    return {"message": "Product not found"}