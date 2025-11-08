#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertBeforeAfter(Node*& head, int value, int newValue, bool before) {
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }
    if (before && head->data == value) {
        insertAtBeginning(head, newValue);
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (before) {
            if (temp->next != NULL && temp->next->data == value) {
                Node* newNode = createNode(newValue);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
        } else { 
            if (temp->data == value) {
                Node* newNode = createNode(newValue);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
        }
        temp = temp->next;
    }
    cout << "Value " << value << " not found in list.\n";
}
void deletefrombeginning(Node*& head){
	Node *temp=head;
	head=head->next;
	delete temp;
	return;
	}
void deleteatend(Node*& head){
	while(head->next->next!=NULL){
		head=head->next;
	}
	head->next=NULL;
	head=head->next;
	delete head;
	return;
}	
void deleteatnode(Node* head,int value){
	while(head->next!=NULL && head->next->data!=value){
		head=head->next;
	}
	head->next=head->next->next;
	return;
}
void searchNode(Node* head, int value) {
    int pos = 1;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value " << value << " not found in the list.\n";
}


void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List: ";
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    int choice, value, target;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Value\n";
        cout << "4. Insert After a Value\n";
        cout << "5.Delete at Beginning\n";
        cout << "6.Delete at End\n";
        cout << "7.Delete at value\n";
        cout << "8.search and display its position\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 3:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                insertBeforeAfter(head, target, value, true);
                break;

            case 4:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                insertBeforeAfter(head, target, value, false);
                break;
            case 5:
			cout<<"deleting at beginning";
			deletefrombeginning(head); 
			break;
			case 6:
			cout<<"Deleting from end";
			deleteatend(head);
			break;
			case 7:
			cout<<"enter the value you want to delete";
			cin>>value;
			deleteatnode(head,value);
			break;   
            case 8:
            	cout<<"enter the value you want to display its position of";
            	cin>>value;
            	searchNode(head,value);
            	break;
            	
            case 9:
                display(head);
                break;

            case 10:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}