#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Deque {
private:
    int items[MAX_SIZE];
    int front, rear;

public:
    Deque() {
        front = rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueueFront(int value) {
        if (isFull()) {
            cout << "\nDeque is Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        items[front] = value;
    }

    void enqueueRear(int value) {
        if (isFull()) {
            cout << "\nDeque is Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        items[rear] = value;
    }

    void dequeueFront() {
        if (isEmpty()) {
            cout << "\nDeque is empty\n";
            return;
        }

        cout << "\nDequeued from front: " << items[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void dequeueRear() {
        if (isEmpty()) {
            cout << "\nDeque is empty\n";
            return;
        }

        cout << "\nDequeued from rear: " << items[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }

    int peekFront() {
        if (isEmpty()) {
            cout << "\nDeque is empty\n";
            return -1;
        }

        return items[front];
    }

    int peekRear() {
        if (isEmpty()) {
            cout << "\nDeque is empty\n";
            return -1;
        }
        return items[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "\nDeque is empty\n";
            return;
        }

        cout << "\nDeque elements are: ";
        int i = front;
        while(true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, value;

    do {
        system("clear");
        dq.display();
        cout << "\nDeque Menu:\n";
        cout << "1. Enqueue Front\n";
        cout << "2. Enqueue Rear\n";
        cout << "3. Dequeue Front\n";
        cout << "4. Dequeue Rear\n";
        cout << "5. Peek Front and Rear\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue at front: ";
            cin >> value;
            dq.enqueueFront(value);
            break;

        case 2:
            cout << "Enter value to enqueue at rear: ";
            cin >> value;
            dq.enqueueRear(value);
            break;

        case 3:
            dq.dequeueFront();
            break;

        case 4:
            dq.dequeueRear();
            break;

        case 5:
            cout << "\nPeek Front: " << dq.peekFront();
            cout << "\nPeek Rear: " << dq.peekRear() << "\n";
            break;

        case 6:
            dq.display();
            break;

        case 7:
            cout << "\nExiting...\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

        cout << "\n";
        system("pause");
    } while (choice != 7);

    return 0;
}