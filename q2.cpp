#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

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

int deleteOccurrences(int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* t = temp->next;
            temp->next = temp->next->next;
            delete t;
            count++;
        } else {
            temp = temp->next;
        }
    }
    return count;
}

void displayList() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, val, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(val);
    }
    cin >> key;
    int count = deleteOccurrences(key);
    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    displayList();
    return 0;
}
