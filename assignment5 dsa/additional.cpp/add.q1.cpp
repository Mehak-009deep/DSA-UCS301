#include <iostream>
#include <cmath>
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

void insert(node*& head, int d) {
    node* newnode = new node(d);

    if (!head) {
        head = newnode;
        return;
    }

    node* cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = newnode;
}

int getlength(node* head) {
    int length = 0;
    node* cur = head;

    while (cur) {
        length++;
        cur = cur->next;
    }
    return length;
}

int commonnode(node*& head1, node*& head2) {
    int l1 = getlength(head1);
    int l2 = getlength(head2);
    
    int diff = abs(l1 - l2);

    node* p1 = head1;
    node* p2 = head2;

    if (l1 > l2) {
        while (diff--) p1 = p1->next;
    } else {
        while (diff--) p2 = p2->next;
    }

    while (p1 && p2) {
        if (p1 == p2)
            return p1->data;
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}

int main() {

    node* common = new node(7);
    common->next = new node(9);

    node* head1 = NULL;
    insert(head1, 3);
    insert(head1, 6);

    node* tail1 = head1;
    while (tail1->next)
        tail1 = tail1->next;
    tail1->next = common;

    node* head2 = NULL;
    insert(head2, 10);
    insert(head2, 4);

    node* tail2 = head2;
    while (tail2->next)
        tail2 = tail2->next;
    tail2->next = common;

    int ans = commonnode(head1, head2);

    if (ans != -1)
        cout << "Intersection at node with data: " << ans << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}