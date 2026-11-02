#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[1000];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int val) {
        if (size == 1000) return;

        int i = size++;
        arr[i] = val;

        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(20);
    pq.insert(40);

    pq.display();

    return 0;
}