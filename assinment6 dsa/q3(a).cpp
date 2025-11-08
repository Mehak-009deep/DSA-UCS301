#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void inserttail(node*& head, node*& tail, int val) {
    node* temp = new node(val);

    if (!head) { 
        head = tail = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void print(node*& head) {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "Doubly Linked List: ";
    for (node* p = head; p != NULL; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}
int getlen(node*& head) {
    int count = 0;
    for (node* p = head; p != NULL; p = p->next) {
        count++;
    }
    return count;
}
int main() {
    node* head = NULL;
    node* tail = NULL;

    inserttail(head, tail, 10);
    inserttail(head, tail, 4);
    inserttail(head, tail, 15);
    inserttail(head, tail, 2);
    inserttail(head, tail, 6);
    print(head);
    cout << "Length of List: " << getlen(head) << endl;
    return 0;
}