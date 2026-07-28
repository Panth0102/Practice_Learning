#include <iostream>
using namespace std;

int* create(int& size);
void insertAtBeginning(int*& arr, int& size);
void insertAtPosition(int*& arr, int& size);
void insertAtEnd(int*& arr, int& size);
void display(int arr[], int size);
void change(int arr[], int size);
void displayOne(int arr[], int size);
void search(int arr[], int size);
void delAtPos(int arr[], int& size);
void delAtBeginning(int arr[], int& size);
void delAtEnd(int arr[], int& size);
void delByValue(int*& arr, int& size);

int main() {
    int size = 0;
    int choice;
    int* arr = create(size);
    while (1) {
        cout << "----MENU----" << endl << endl;
        cout << "1. Display All" << endl;
        cout << "2. Display One" << endl;
        cout << "3. Change a value" << endl;
        cout << "4. Search a value" << endl;
        cout << "5. Delete by Value" << endl;
        cout << "6. Insertion at Begining" << endl;
        cout << "7. Insertion at Position" << endl;
        cout << "8. Insertion at End" << endl;
        cout << "9. Delete at Beginning" << endl;
        cout << "10. Delete at Postion" << endl;
        cout << "11. Delete at End" << endl;

        cout << "0. Exit" << endl << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case 1: display(arr, size); break;
        case 2: displayOne(arr, size); break;
        case 3: change(arr, size); break;
        case 4: search(arr, size); break;
        case 5: delByValue(arr, size); break;
        case 6: insertAtBeginning(arr, size); break;
        case 7: insertAtPosition(arr, size); break;
        case 8: insertAtEnd(arr, size); break;
        case 9: delAtBeginning(arr, size); break;
        case 10: delAtPos(arr, size); break;
        case 11: delAtEnd(arr, size); break;

        case 0:
            delete[] arr; exit(0);
        }
        cout << endl;
    }
    return 0;
}

//  ---------------------------------- ---------------CREATE------------------- ----------------------------------

int* create(int& size) {
    cout << "Enter size for the array : ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter value at " << i << " : ";
        cin >> arr[i];
    }

    return arr;
}

//  ---------------------------------- ---------------DISPLAY------------------- ----------------------------------

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayOne(int arr[], int size) {
    int pos;
    cout << "Enter a position to search : ";
    cin >> pos;

    if (pos >= 0 && pos < size) {
        cout << "The value at position " << pos << " is : " << arr[pos] << endl;
    }
    else {
        cout << "No such value found" << endl;
    }
}

//  ---------------------------------- ---------------SEARCH-CHANGE------------------- ----------------------------------

void change(int arr[], int size) {
    if (size == 0) cout << "Array is empty" << endl; return;

    int pos;
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

void search(int arr[], int size) {
    if (size == 0) cout << "Array is empty" << endl; return;

    int key;
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

//  ---------------------------------- ---------------INSERTION------------------- ----------------------------------

void insertAtBeginning(int*& arr, int& size) {
    int val;
    cout << "Enter value to be inserted : ";
    cin >> val;

    int* newarr = new int[size + 1];
    newarr[0] = val;

    for (int i = 0; i < size; i++) {
        newarr[i + 1] = arr[i];
    }

    delete[] arr;

    arr = newarr;
    size++;
}

void insertAtPosition(int*& arr, int& size) {
    int pos, val;
    cout << "Enter a postion to insert : ";
    cin >> pos;
    if (pos == 0) {
        insertAtBeginning(arr, size);
    }
    else if (pos = size) {
        insertAtEnd(arr, size);
    }
    else if (pos > 0 && pos < size) {
        cout << "Enter value to be inserted : ";
        cin >> val;
        int* newarr = new int[size + 1];

        for (int i = 0; i < pos; i++) {
            newarr[i] = arr[i];
        }
        newarr[pos] = val;
        for (int i = pos; i < size; i++) {
            newarr[i + 1] = arr[i];
        }

        delete[] arr;

        arr = newarr;
        size++;
    }
    else {
        cout << "Invalid Position";
    }
}

void insertAtEnd(int*& arr, int& size) {
    int val;
    cout << "Enter value to be inserted : ";
    cin >> val;
    int* newarr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newarr[i] = arr[i];
    }

    newarr[size] = val;
    delete[] arr;

    arr = newarr;
    size++;
}

//  ---------------------------------- ---------------DELETE------------------- ----------------------------------

void delAtBeginning(int arr[], int& size) {
    if (size == 0) cout << "Array is empty" << endl; return;
    
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void delAtPos(int arr[], int& size) {
    if (size == 0) cout << "Array is empty" << endl; return;

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
}

void delAtEnd(int arr[], int& size) {
    if (size == 0) cout << "Array is empty" << endl; return;

    size--;
}

void delByValue(int*& arr, int& size) {
    if (size == 0) cout << "Array is empty" << endl; return;
    
    int val;
    cout << "Enter a value to delete : ";
    cin >> val;
    bool check = false;
    int pos = -1;

    for (int i = 0; i < size && check == false; i++) {
        if (arr[i] == val) {
            pos = i;
            check = true;
        }
    }

    if (!check) {
        cout << "Value not found" << endl;
        return;
    }

    int* newarr = new int[size - 1];
    for (int i = 0; i < pos; i++) {
        newarr[i] = arr[i];
    }
    for (int i = pos; i < size - 1; i++) {
        newarr[i] = arr[i + 1];
    }

    delete[] arr;
    arr = newarr;

    size--;
}


//  ---------------------------------- ---------------SORTING------------------- ----------------------------------

//