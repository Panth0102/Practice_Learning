#include<iostream>
using namespace std;

#define MAX_SIZE 10

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
            cout << "Rear element: " << arr[rear] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue Elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << ", ";
        }
        cout << "\b\b " << endl;
    }


};

void showMenu() {
    cout << "\n==== Queue Menu ====\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek (Front and Rear)\n";
    cout << "4. Check if Queue is Empty\n";
    cout << "5. Check if Queue is Full\n";
    cout << "6. Display Queue\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Queue q;
    int choice, value;

    do {
        system("pause");
        system("clear");
        q.display();
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;

            case 5:
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;

            case 6:
                q.display();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}