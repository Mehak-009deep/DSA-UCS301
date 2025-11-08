#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
int countAndDelete(Node*& head, int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
        count++;
    }

    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            count++;
        } else {
            temp = temp->next;
        }
    }

    return count;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << "->";
        head = head->next;
    }
    cout << endl;
}
main() {
    Node* head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 1);

    cout << "Original List: ";
    display(head);

    int key = 1;
    int count = countAndDelete(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    display(head);

    return 0;
}