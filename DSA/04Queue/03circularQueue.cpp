#include<iostream>
using namespace std;
class MyCircularQueue {
    int  front,rear,size;
    vector<int> arr;
public: 
    MyCircularQueue(int k) {
        size=k;
        front=rear=-1;
        arr.resize(k);
    }   
    
    bool enQueue(int value) {
        if (isFull()) return false;
        isEmpty() ? front = rear = 0 : rear == size-1? rear = 0 :rear++;
        arr[rear] = value;
        return true;
    }   
    
    bool deQueue() {
        if (isEmpty()) return false;
        front == rear? front = rear = -1 : front==size-1? front = 0 : front++;
        return true;
    }
    
    int Front() { return isEmpty() ? -1 : arr[front]; }
    
    int Rear() { return isEmpty() ? -1 : arr[rear]; }
    
    bool isEmpty() { return front == -1; }
    
    bool isFull() { return ((rear + 1) % size) == front;}
    
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "\n";
    }
};

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;
    MyCircularQueue q(size);

    int choice, value;
    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front Element\n";
        cout << "4. Rear Element\n";
        cout << "5. Display Queue\n";
        cout << "6. Check if Empty\n";
        cout << "7. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                if (q.enQueue(value))
                    cout << "Enqueued " << value << ".\n";
                else
                    cout << "Queue is full. Cannot enqueue.\n";
                break;
            case 2:
                if (q.deQueue())
                    cout << "Dequeued successfully.\n";
                else
                    cout << "Queue is empty. Cannot dequeue.\n";
                break;
            case 3:
                value = q.Front();
                if (value != -1)
                    cout << "Front element: " << value << "\n";
                else
                    cout << "Queue is empty.\n";
                break;
            case 4:
                value = q.Rear();
                if (value != -1)
                    cout << "Rear element: " << value << "\n";
                else
                    cout << "Queue is empty.\n";
                break;
            case 5:
                q.displayQueue();
                break;
            case 6:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 7:
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}