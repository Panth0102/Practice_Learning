#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node (int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int data, int position) {
        if (position < 1) {
            cout << "Invalid position!\n";
            return;
        }

        if (position == 1) {
            insertAtBeginning(data);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position is out of bounds!" << endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }
    
    void printForward() {
        Node* temp = head;
        cout << "\nList (Forward): ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void printBackward() {
        if (!head) {
            cout << "\nList (Backward): NULL\n";
            return;
        }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        cout << "\nList (Backward): ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAtPosition(int pos) {
        if (!head || pos < 1) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos && temp; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        if (!temp->next) {
            deleteAtEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void reverse() {
        Node* temp = nullptr;
        while (head) {
            temp = head->next;
            head->next = head->prev;
            head->prev = temp;
            if (!temp) break;
            head = temp;
        }
    }
};



// 1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10
int main() {
    DoublyLinkedList list;
    int choice, data, pos, key;

    while (true) {
        system("cls");
        list.printForward();

        cout << "\n\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert at Position";
        cout << "\n4. Delete at Beginning";
        cout << "\n5. Delete at End";
        cout << "\n6. Delete at Position";
        cout << "\n7. Search by Value";
        cout << "\n8. Get Length";
        cout << "\n9. Reverse List";
        cout << "\n10. Print Forward";
        cout << "\n11. Print Backward";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            list.insertAtBeginning(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            list.insertAtEnd(data);
            break;
        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter data: ";
            cin >> data;
            list.insertAtPosition(data, pos);
            break;
        case 4:
            list.deleteAtBeginning();
            break;
        case 5:
            list.deleteAtEnd();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> key;
            // if (list.search(key))
            //     cout << key << " found in the list.\n";
            // else
            //     cout << key << " not found in the list.\n";
            // cout << "\nPress Enter to continue...\n";
            // cin.ignore();
            // cin.get();
            break;
        case 8:
            // cout << "Length: " << list.getLength() << "\n";
            cout << "\nPress Enter to continue...\n";
            cin.ignore();
            cin.get();
            break;
        case 9:
            list.reverse();
            break;
        case 10:
            list.printForward();
            cout << "\nPress Enter to continue...\n";
            cin.ignore();
            cin.get();
            break;
        case 11:
            list.printBackward();
            cout << "\nPress Enter to continue...\n";
            cin.ignore();
            cin.get();
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
            cout << "\nPress Enter to continue...\n";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}