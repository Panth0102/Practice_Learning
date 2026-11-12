
#include <iostream>
#include <algorithm>
using namespace std;

class PriorityQueue {
    int arr[1000];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    // Insert element
    void insert(int val) {
        if (size == 1000) {
            cout << "Priority Queue is Full!\n";
            return;
        }

        int i = size++;
        arr[i] = val;

        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }

        cout << val << " inserted successfully.\n";
    }

    // Delete highest priority element
    void remove() {
        if (size == 0) {
            cout << "Priority Queue is Empty!\n";
            return;
        }

        cout << "Deleted Element: " << arr[0] << endl;

        arr[0] = arr[size - 1];
        size--;

        int i = 0;

        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && arr[left] > arr[largest])
                largest = left;

            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest == i)
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    // Display highest priority element
    void peek() {
        if (size == 0) {
            cout << "Priority Queue is Empty!\n";
            return;
        }

        cout << "Highest Priority Element: " << arr[0] << endl;
    }

    // Display all elements
    void display() {
        if (size == 0) {
            cout << "Priority Queue is Empty!\n";
            return;
        }

        cout << "Priority Queue: ";

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Return number of elements
    void getSize() {
        cout << "Current Size: " << size << endl;
    }

    // Return highest priority element
    int getMax() {
        if (size == 0) {
            cout << "Priority Queue is Empty!\n";
            return -1;
        }

        return arr[0];
    }

    // Search for an element
    void search(int val) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                cout << val << " found at index " << i << endl;
                return;
            }
        }

        cout << val << " not found in Priority Queue.\n";
    }
};

int main() {
    PriorityQueue pq;
    int choice, val;

    do {
        cout << "\n----- PRIORITY QUEUE MENU -----\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Get Size\n";
        cout << "6. Get Maximum Element\n";
        cout << "7. Search Element\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                pq.insert(val);
                break;

            case 2:
                pq.remove();
                break;

            case 3:
                pq.peek();
                break;

            case 4:
                pq.display();
                break;

            case 5:
                pq.getSize();
                break;

            case 6:
                cout << "Maximum Element: " << pq.getMax() << endl;
                break;
                
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                pq.search(val);
                break;
            case 0:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 0);

    return 0;
}
