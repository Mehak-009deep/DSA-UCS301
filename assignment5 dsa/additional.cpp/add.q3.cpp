#include<iostream>
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
node* floyddetect(node* head) {
    if (head == NULL) return NULL;
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) return slow; 
    }
    return NULL;
}
node* startingnode(node* head) {
    node* fast = floyddetect(head);
    if (fast == NULL) return NULL;
    node* slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; 
}
void removeloop(node* head) {
    node* start = startingnode(head);
    if (start == NULL) return;
    node* temp = start;
    while (temp->next != start){
        temp = temp->next;
    }
    temp->next = NULL;
}
void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    node* head = new node(1);
    node* n2 = new node(7);
    node* n3 = new node(3);
    node* n4 = new node(6);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    if (floyddetect(head) != NULL) {
        cout << "Loop detected\n";
        removeloop(head);
        cout << "After removing loop: ";
        print(head);
    } 
    else cout << "No loop found";
    return 0;
}