#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node* link;

    Node(int v) {
        value = v;
        link = NULL;
    }
};
void addLast(Node*& last, int val) {
    Node* temp = new Node(val);

    if (last == NULL) {
        last = temp;
        last->link = last;
    } else {
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
}
void display(Node* last) {
    if (last == NULL) {
        cout << "List is Empty\n";
        return;
    }
    
    Node* start = last->link;
    cout << "Circular Linked List: ";
    
    do {
        cout << start->value << " ";
        start = start->link;
    } while (start != last->link);

    cout << endl;
}

int main() {
    Node* last = NULL;

    addLast(last, 20);
    addLast(last, 100);
    addLast(last, 40);
    addLast(last, 80);
    addLast(last, 60);

    display(last);

    return 0;
}