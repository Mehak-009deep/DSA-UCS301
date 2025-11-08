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
void insert(node*&tail,int d){
    node*n=new node(d);
    if(tail==NULL){
        tail=n;
        return;
    }
    tail->next=n;
    tail=n;
}
node* rotate(node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    node* temp = head;
    int length = 1; 
    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    temp->next = head;
    k = k % length;
    if(k == 0) { 
        temp->next = NULL;
        return head;
    }
    node* ntail = head;
    for(int i = 1; i < k; i++) {
        ntail = ntail->next;
    }
    node* nhead = ntail->next;
    ntail->next = NULL;
    return nhead;
}
void print(node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    node* n = new node(10);
    node* head = n;
    node* tail = n;
    insert(tail,20);
    insert(tail,30);
    insert(tail,40);
    insert(tail,50);
    int k;
    cout << "Enter k:";
    cin >> k;
    node* nhead = rotate(head, k);
    print(nhead);
    return 0;
}