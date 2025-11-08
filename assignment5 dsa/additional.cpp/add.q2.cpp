#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int d) {
        this->data = d;
        this->next = NULL;
    }
};
void insert(node*& tail, int d) {
    node* n = new node(d);
    if (tail == NULL) {
        tail = n;
        return;
    }
    tail->next = n;
    tail = n;
}
void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node* reverse(node* head, int k) {
    if (head == NULL) return NULL;
    node* curr = head;
    node* ptail = NULL;
    node* nhead = NULL;
    while (curr != NULL) {
        node* HEAD = curr;
        node* prev = NULL;
        int count = 0;
        node* temp = curr;
        int cnt = 0;
        while (temp != NULL && cnt < k) {
            temp = temp->next;
            cnt++;
        }
        if (cnt < k) break; 
        while (curr != NULL && count < k) {
            node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        if (ptail != NULL)  ptail->next = prev;
        else  nhead = prev; 
        ptail = HEAD; 
    }
    if (ptail != NULL)  ptail->next = curr; 
    return nhead == NULL ? head : nhead;
}
int main() {
    node* head = new node(1);
    node* tail = head;
    for (int i = 2; i <= 8; i++) insert(tail, i);
    cout << "Original list: ";
    print(head);
    int k;
    cout << "Enter k in whose groups list will be reversed: ";
    cin >> k;
    head = reverse(head, k);
    cout << "New list: ";
    print(head);
    return 0;
}