#include <iostream>
using namespace std;

class Array {
    int size;
    int* arr;
    int pos;
    int key;

public:
    Array() {
        size = 0;
        pos = 0;
        key = 0;
        arr = nullptr;
    }

    Array(int size) {
        this->size = size;
        this->arr = new int[size];
        this->pos = 0;
        this->key = 0;
    }

    void create() {
        for (int i = 0; i < size; i++) {
            cout << "Enter value at " << i << " : ";
            cin >> arr[i];
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void displayOne() {
        cout << "Enter a position to search : ";
        cin >> pos;

        if (pos >= 0 && pos < size) {
            cout << "The value at position " << pos << " is : " << arr[pos] << endl;
        }
        else {
            cout << "No such value found" << endl;
        }
    }

    void change() {
        cout << "Enter a position to change : ";
        cin >> pos;

        if (pos >= 0 && pos < size) {
            cout << "Enter a value to change : ";
            cin >> arr[pos];
        }
        else {
            cout << "No value found" << endl;
        }
    }

    void search() {
        cout << "Enter a value to search : ";
        cin >> key;
        bool val = false;
        int pos = 0;

        for (int i = 0; i < size; i++) {
            if (key == arr[i]) {
                val = true;
                pos = i;
                break;
            }
        }
        cout << (val ? "Position found at : " + to_string(pos) : "Not found") << endl;
    }

    void delAtPos() {
        int pos;
        cout << "Enter a position to delete : ";
        cin >> pos;

        if (pos < 0 || pos >= size) {
            cout << "No such position to delete" << endl;
        }
        else {
            for (int i = pos; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        }
        display();
    }
    ~Array() {
        delete[] arr;
    }
};

int main() {
    int userSize;
    cout << "Enter size for the array: ";
    cin >> userSize;

    Array myArr(userSize);
    myArr.create();
    myArr.display();
    myArr.displayOne();
    myArr.change();
    myArr.search();
    myArr.delAtPos();

    return 0;
}