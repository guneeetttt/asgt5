#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void insertBefore(int val, int key) {
    if (head == NULL) return;
    if (head->data == key) {
        insertAtBeginning(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;
    if (temp->next == NULL) return;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(int val, int key) {
    Node* temp = head;
    while (temp != NULL && temp->data != key) temp = temp->next;
    if (temp == NULL) return;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteNode(int key) {
    if (head == NULL) return;
    if (head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;
    if (temp->next == NULL) return;
    Node* t = temp->next;
    temp->next = t->next;
    delete t;
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found" << endl;
}

void displayList() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int choice, val, key;
    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search a Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertAtEnd(val); break;
            case 3: cout << "Enter value to insert: "; cin >> val; cout << "Enter node value before which to insert: "; cin >> key; insertBefore(val, key); break;
            case 4: cout << "Enter value to insert: "; cin >> val; cout << "Enter node value after which to insert: "; cin >> key; insertAfter(val, key); break;
            case 5: deleteFromBeginning(); break;
            case 6: deleteFromEnd(); break;
            case 7: cout << "Enter value to delete: "; cin >> val; deleteNode(val); break;
            case 8: cout << "Enter value to search: "; cin >> key; searchNode(key); break;
            case 9: displayList(); break;
            case 10: return 0;
            default: cout << "Invalid choice" << endl;
        }
    }
}
