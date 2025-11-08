#include <iostream>
using namespace std;

class node {
public:
    char data;
    node* next;
    node* prev;
    
    node(char data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void inserttail(node*& head, node*& tail, char d) {
    node* temp = new node(d);

    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void print(node*& head) {
    for(node* temp = head; temp != NULL; temp = temp->next)
        cout << temp->data << " ";
    cout << endl;
}

int getlen(node*& head) {
    int cnt = 0;
    for(node* temp = head; temp != NULL; temp = temp->next)
        cnt++;
    return cnt;
}

bool palindrome(node* head, node* tail) {
    while(head != tail && head->prev != tail) {
        if(head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    node* head = NULL;
    node* tail = NULL;

    inserttail(head, tail, 'l');
    inserttail(head, tail, 'e');
    inserttail(head, tail, 'v');
    inserttail(head, tail, 'e');
    inserttail(head, tail, 'l');

    print(head);

    if(palindrome(head, tail))
        cout << "true";
    else 
        cout << "false";

    return 0;
}