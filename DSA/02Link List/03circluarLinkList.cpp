#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

    Node* getTail() {
        if (!head) return nullptr;
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        return temp;
    }

public:
    LinkedList() { head = nullptr; }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* tail = getTail();
        newNode->next = head;
        head = newNode;
        tail->next = head; 
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head; 
            return;
        }

        Node* tail = getTail();
        tail->next = newNode;
        newNode->next = head; 
    }

    void insertAtPosition(int data, int position) {
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(data);
            return;
        }

        int length = getLength();
        if (position > length + 1) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int searchByValue(int key) {
        if (!head) return -1;

        int idx = 1;
        Node* temp = head;
        do {
            if (temp->data == key) return idx;
            temp = temp->next;
            idx++;
        } while (temp != head);

        return -1;
    }

    int getLength() {
        if (!head) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    // void reverseList() {
    //     if (!head || head->next == head) return;
    
    //     Node* prev = nullptr;
    //     Node* curr = head;
    //     Node* next = nullptr;
    //     Node* first = head; 
    
    //     do {
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     } while (curr != head);
    
    //     first->next = prev; 
    //     head = prev;        
    // }

    void reverseList() {
        if (!head || head->next == head) return;
        Node* temp = head->next;
        head->next = head;
        while (temp != head) {
            Node* next = temp->next;
            temp->next = head;
            head = temp;
            temp = next;
        }
    }
    

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        if (head->next == head) { 
            delete head;
            head = nullptr;
            return;
        }

        Node* tail = getTail();
        Node* temp = head;
        head = head->next;
        tail->next = head; 
        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        if (head->next == head) { 
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head; 
    }

    void deleteAtPosition(int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        int length = getLength();
        if (pos > length) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void printList() {
        if (head == nullptr) {
            cout << "\nList is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "\nList: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};

int main() {
    LinkedList list;
    int choice, data, pos, key, index;

    while (true) {
        system("clear");
        list.printList();

        cout << "\n\n1. Insert at beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert at Position";
        cout << "\n4. Search By Value";
        cout << "\n5. Length of the list";
        cout << "\n6. Reverse the List";
        cout << "\n7. Delete at beginning";
        cout << "\n8. Delete at end";
        cout << "\n9. Delete at Position";
        cout << "\n10. Print list from beginning";
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
            cout << "Enter value to search: ";
            cin >> key;
            index = list.searchByValue(key);
            if (index != -1)
                cout << key << " found at position: " << index << "\n";
            else
                cout << key << " not found in the list.\n";
            break;
        case 5:
            cout << "Length: " << list.getLength() << "\n";
            break;
        case 6:
            list.reverseList();
            break;
        case 7:
            list.deleteAtBeginning();
            break;
        case 8:
            list.deleteAtEnd();
            break;
        case 9:
            cout << "Enter position to delete: ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;
        case 10:
            list.printList();
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
