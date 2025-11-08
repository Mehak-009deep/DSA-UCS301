#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void inserttail(node* &tail, int d) {
    node* temp = new node(d);

    if(tail == NULL) { 
        tail = temp;
        temp->next = temp;
    }
    else {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}

void print(node* &head) {
    if(head == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }

    node* temp = head;
    while(true) {
        cout << temp->data << " ";
        temp = temp->next;
        if(temp == head) 
            break;
    }
    cout << endl;
}

int getlen(node* head) {
    if(head == NULL) return 0;
    
    int cnt = 0;
    node* temp = head;
    while(true) {
        cnt++;
        temp = temp->next;
        if(temp == head)
            break;
    }
    return cnt;
}

int main() {
    node* head = new node(5);
    node* tail = head;
    head->next = head;

    inserttail(tail, 10);
    inserttail(tail, 4);
    inserttail(tail, 15);
    inserttail(tail, 2);
    inserttail(tail, 6);

    print(head);
    cout << "Length: " << getlen(head) << endl;

    return 0;
}