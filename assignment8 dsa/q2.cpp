#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(!root) return new Node(val);
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* searchRec(Node* root, int key){
    if(!root || root->data == key) return root;
    if(key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchNonRec(Node* root, int key){
    while(root){
        if(root->data == key) return root;
        if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* findMin(Node* root){
    while(root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root){
    while(root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x){
    Node* succ = NULL;
    while(root){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x){
    Node* pred = NULL;
    while(root){
        if(x->data > root->data){
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}

int main(){
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    Node* x = searchRec(root, 15);
    cout<<"Search Recursive: "<<(x ? "Found" : "Not Found")<<"\n";

    x = searchNonRec(root, 25);
    cout<<"Search Non-Recursive: "<<(x ? "Found" : "Not Found")<<"\n";

    cout<<"Min: "<<findMin(root)->data<<"\n";
    cout<<"Max: "<<findMax(root)->data<<"\n";

    Node* node = searchRec(root, 25);
    Node* s = inorderSuccessor(root, node);
    Node* p = inorderPredecessor(root, node);
    cout<<"Successor of 25: "<<(s ? to_string(s->data) : "None")<<"\n";
    cout<<"Predecessor of 25: "<<(p ? to_string(p->data) : "None")<<"\n";

    return 0;
}