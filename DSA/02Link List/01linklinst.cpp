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

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
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

        Node* temp = head;
        for(int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int searchByValue(int key) {
        int idx = 0;
        Node* temp = head;
        while(temp != nullptr) {
            idx++;
            if (temp->data == key) 
                return idx;
            temp = temp->next;
        }
        return -1;
    }

    int getLength() {
        int idx = 0;
        Node* temp = head;
        while(temp != nullptr) {
            idx++;
            temp = temp->next;
        }
        return idx;
    }

    // void reverseList() {
    //     Node* prev = nullptr;
    //     Node* curr = head;
    //     Node* next = nullptr;

    //     while(curr != nullptr) {
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }
    //     head = prev;
    // }

    void reverseList() {
        Node* temp = nullptr;
        while (head != nullptr) {
            Node* next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }
        head = temp;
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is emtpy!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is emtpy!\n";
            return;
        }

        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        
        delete temp->next;
        temp->next = nullptr;
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
        Node* temp = head;
        for(int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void printList() {
        Node* temp = head;
        cout << "\nList: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

};

// 1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10
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
        cout << "\n11. Print list from end";
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
            cout << "\nPress any key to continue...\n";
            cin.ignore();
            cin.get();
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> key;
            index = list.searchByValue(key);
            if (index != -1)
                cout << key << " found at position: " << index << "\n";
            else
                cout << key << " not found in the list.\n";
            cout << "\nPress any key to continue...\n";
            cin.ignore();
            cin.get();
            break;
        case 5:
            cout << "Length: " << list.getLength() << "\n";
            cout << "\nPress any key to continue...\n";
            cin.ignore();
            cin.get();break;
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
            cout << "\nPress any key to continue...\n";
            cin.ignore();
            cin.get();
            break;
        case 10:
            list.printList();
            cout << "\nPress any key to continue...\n";
            cin.ignore();
            cin.get();
            break;
        /*case 11:
            list.printFromEnd();
            cout << "\nPress any key to continue...\n";
            cin.ignore();
            cin.get();
            break;*/
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
            cout << "\nPress any key to continue...\n";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}