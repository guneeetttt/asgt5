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

int findMiddle() {
    if (head == NULL) return -1;
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(val);
    }
    cout << findMiddle() << endl;
    return 0;
}
