#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        next = NULL;
    }
};
void inserttail(node*& tail, int d) {
    node* temp = new node(d);

    if (tail == NULL) {
        tail = temp;
        tail->next = temp;
    }
    else {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}
bool iscircular(node* head) {
    if (head == NULL)
        return false;

    node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;

    return (temp == head);
}
void print(node*& head) {
    if (!head) return;

    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } 
    while (temp != head);

    cout << endl;
}
int main() {
    node* head = NULL;
    node* tail = NULL;

    inserttail(tail, 2);
    head = tail;
    inserttail(tail, 4);
    inserttail(tail, 6);
    inserttail(tail, 7);
    inserttail(tail, 5);

    print(head);

    if (iscircular(head))
        cout << "True";
    else
        cout << "False";
    return 0;
}