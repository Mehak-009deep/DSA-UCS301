#include <iostream>
using namespace std;
class CDLL {
public:
    int info;
    CDLL* next;
    CDLL* prev;
    CDLL(int val) {
        info = val;
        next = prev = NULL;
    }
};
void insertAtStart(CDLL*& last, int val) {
    CDLL* nn = new CDLL(val);

    if (!last) {
        last = nn;
        last->next = last->prev = last;
        return;
    }
    CDLL* first = last->next;
    nn->next = first;
    nn->prev = last;
    first->prev = nn;
    last->next = nn;
}
void insertAtRef(CDLL*& last, int val, int ref, bool after = true) {
    if (!last) {
        cout << "List is empty! Adding as first node.\n";
        insertAtStart(last, val);
        return;
    }

    CDLL* nn = new CDLL(val);
    CDLL* ptr = last->next;

    do {
        if (ptr->info == ref) {
            if (after) {
                nn->next = ptr->next;
                nn->prev = ptr;
                ptr->next->prev = nn;
                ptr->next = nn;
                if (ptr == last) last = nn;
            } else {
                nn->next = ptr;
                nn->prev = ptr->prev;
                ptr->prev->next = nn;
                ptr->prev = nn;
                if (ptr == last->next) last->next = nn;
            }
            return;
        }
        ptr = ptr->next;
    } while (ptr != last->next);

    cout << "Reference value not found!\n";
}
void removeNode(CDLL*& last, int key) {
    if (!last) {
        cout << "List is empty!\n";
        return;
    }

    CDLL* ptr = last->next;

    do {
        if (ptr->info == key) {
            if (ptr->next == ptr) {
                delete ptr;
                last = NULL;
                return;
            }

            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            if (ptr == last) last = ptr->prev;
            delete ptr;
            return;
        }
        ptr = ptr->next;
    } while (ptr != last->next);

    cout << "Node not found!\n";
}
bool findNode(CDLL* last, int value) {
    if (!last) return false;

    CDLL* temp = last->next;
    do {
        if (temp->info == value) return true;
        temp = temp->next;
    } while (temp != last->next);

    return false;
}

void showList(CDLL* last) {
    if (!last) {
        cout << "List Empty!\n";
        return;
    }
    cout << "Circular Doubly Linked List: ";
    CDLL* temp = last->next;
    do {
        cout << temp->info << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}

int main() {
    CDLL* last = NULL;
    int ch, val, ref;
    bool aft;

    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert Before/After Node\n";
        cout << "3. Delete a Node\n";
        cout << "4. Display List\n";
        cout << "5. Search Value\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            insertAtStart(last, val);
            break;

        case 2:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter reference node value: ";
            cin >> ref;
            cout << "Insert after (1) or before (0)? ";
            cin >> aft;
            insertAtRef(last, val, ref, aft);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> val;
            removeNode(last, val);
            break;

        case 4:
            showList(last);
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (findNode(last, val) ? "Value FOUND ?\n" : "Value NOT FOUND ?\n");
            break;

        case 6:
            cout << "Exiting Program...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}