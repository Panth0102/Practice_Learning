#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
    int top;

public:
    int stack_arr[MAX_SIZE];

    Stack() { top = -1; }

    bool push(int);
    int pop();
    int peek();
    bool isFull();
    bool isEmpty();
    int size();
    void printStack();
};

bool Stack::isFull() {
    return top == MAX_SIZE - 1;
}

bool Stack::isEmpty() {
    return top == -1;
}

int Stack::size() {
    return top + 1;
}

bool Stack::push(int value) {
    if (isFull()) {
        cout << "\nStack overflow!\n";
        return false;
    } else {
        stack_arr[++top] = value;
        cout << value << " pushed into the stack\n";
        return true;
    }
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "\nStack underflow!\n";
        return -1;
    } else {
        int poppedValue = stack_arr[top--];
        cout << "Popped " << poppedValue << " from stack\n";
        return poppedValue;
    }
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "\nStack underflow!\n";
        return -1;
    } else {
        return stack_arr[top];
    }
}

void Stack::printStack() {
    if (isEmpty()) {
        cout << "\nStack is empty.\n";
    } else {
        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack_arr[i];
            if (i != 0) cout << ", ";
        }
        cout << "\n";
    }
}

int main() {
    int choice, value;
    Stack stk;

    do {
        system("pause");
        system("clear");
        cout << "\n\n------ Stack Operations ------\n";
        stk.printStack();
        cout << "\n1. Push()\n";
        cout << "2. Pop()\n";
        cout << "3. Peek()\n";
        cout << "4. isEmpty()\n";
        cout << "5. isFull()\n";
        cout << "6. size()\n";
        cout << "7. Display()\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stk.push(value);
            break;

        case 2:
            stk.pop();
            break;

        case 3:
            cout << "Top element is: " << stk.peek() << "\n";
            break;

        case 4:
            cout << "Is Stack Empty? : " << (stk.isEmpty() ? "Yes" : "No") << "\n";
            break;

        case 5:
            cout << "Is Stack Full? : " << (stk.isFull() ? "Yes" : "No") << "\n";
            break;

        case 6:
            cout << "Current size: " << stk.size() << "\n";
            break;

        case 7:
            stk.printStack();
            break;

        case 8:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }
    } while (choice != 8);

    return 0;
}