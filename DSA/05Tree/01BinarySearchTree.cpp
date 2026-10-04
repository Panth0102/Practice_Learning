#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) return new Node(data);

    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inorder(Node* root) {
    if(root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if(root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if(root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void levelOrderTraversal(Node* root) {
    if (!root) return;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    cout << "\nLevel Order Traversal: ";
    while(front < rear) {
        Node* curr = queue[front++];
        cout << curr->data << " ";
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

Node* deleteNode(Node* root, int data) {
    if (!root) return root;
    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left) temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void findMinMax(Node* root, int& min, int& max) {
    if (!root) return;
    if (root->data < min) min = root->data;
    if (root->data > max) max = root->data;
    findMinMax(root->left, min, max);
    findMinMax(root->right, min, max);
}

void insertAtEnd(ListNode*& head, int data) {
    ListNode* newNode = new ListNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* curr = head;
    while(curr->next) curr = curr->next;
    curr->next = newNode;
}

void convertBSTtoLinkedList(Node* root, ListNode*& head) {
    if (!root) return;
    convertBSTtoLinkedList(root->left, head);
    insertAtEnd(head, root->data);
    convertBSTtoLinkedList(root->right, head);
}

void printList(ListNode* head) {
    if (!head) {
        cout << "\nList is Empty!" << endl;
        return;
    }
    ListNode* curr = head;
    while (curr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void serializeTree(Node* root, ofstream& out) {
    if (!root) {
        out << "N ";
        return;
    }
    out << root->data << " ";
    serializeTree(root->left, out);
    serializeTree(root->right, out);
}

Node* deserializeTree(ifstream& in) {
    string val;
    in >> val;
    if (val == "N") return nullptr;
    Node* root = new Node(stoi(val));
    root->left = deserializeTree(in);
    root->right = deserializeTree(in);
    return root;
}

Node* findLCA(Node* root, int n1, int n2) {
    if (!root || root->data == n1 || root->data == n2) return root;
    Node* left = findLCA(root->left, n1, n2);
    Node* right = findLCA(root->right, n1, n2);
    if (left && right) return root;
    return left ? left : right;
}

void pruneTree(Node*& root) {
    if (root) {
        pruneTree(root->left);
        pruneTree(root->right);
        delete root;
        root = nullptr;
    }
}

void printTree(Node* root, int space = 0, int indent = 4) {
    if (!root) return;
    space += indent;
    printTree(root->right, space);
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->data << endl;
    printTree(root->left, space);
}

// tree: 1 8 1 3 1 10 1 1 1 6 1 14 1 4 1 7 1 13
int main() {
    Node *root = nullptr, *lca;
    ListNode* head = nullptr;
    int choice, data, minVal, maxVal;

    do {
        system("cls");
        printTree(root);

        cout << "\nBinary Tree Operations Menu\n";
        cout << "1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Height\n";
        cout << "7. Level Order\n8. Delete\n9. Min & Max\n10. BST to Linked List\n";
        cout << "11. Serialize\n12. Deserialize\n13. Find LCA\n14. Prune\n15. Display Tree\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            root = insert(root, data);
            break;
        case 2:
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            system("pause");
            break;
        case 3:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            system("pause");
            break;
        case 4:
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
            system("pause");
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> data;
            cout << (search(root, data) ? "Found\n" : "Not found\n");
            system("pause");
            break;
        case 6:
            cout << "Height: " << height(root) << endl;
            system("pause");
            break;
        case 7:
            levelOrderTraversal(root);
            cout << endl;
            system("pause");
            break;
        case 8:
            cout << "Enter value to delete: ";
            cin >> data;
            root = deleteNode(root, data);
            break;
        case 9:
            minVal = numeric_limits<int>::max();
            maxVal = numeric_limits<int>::min();
            findMinMax(root, minVal, maxVal);
            cout << "Min: " << minVal << ", Max: " << maxVal << endl;
            system("pause");
            break;
        case 10:
            convertBSTtoLinkedList(root, head);
            printList(head);
            system("pause");
            break;
        case 11: {
            ofstream out("tree.txt");
            serializeTree(root, out);
            out.close();
            cout << "Serialized to tree.txt\n";
            system("pause");
            break;
        }
        case 12: {
            ifstream in("tree.txt");
            root = deserializeTree(in);
            in.close();
            printTree(root);
            system("pause");
            break;
        }
        case 13:
            int n1, n2;
            cout << "Enter two nodes: ";
            cin >> n1 >> n2;
            lca = findLCA(root, n1, n2);
            cout << "LCA: " << (lca ? to_string(lca->data) : "Not found") << endl;
            system("pause");
            break;
        case 14:
            pruneTree(root);
            break;
        case 15:
            printTree(root);
            system("pause");
            break;
        case 0:
            cout << "Exiting...\n";
            system("pause");
            break;
        }
    } while (choice != 0);

    return 0;
}