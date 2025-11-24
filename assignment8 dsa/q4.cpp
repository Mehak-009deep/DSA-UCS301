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

bool isBST(Node* root, Node* minNode, Node* maxNode){
    if(!root) return true;
    if(minNode && root->data <= minNode->data) return false;
    if(maxNode && root->data >= maxNode->data) return false;
    return isBST(root->left, minNode, root) && isBST(root->right, root, maxNode);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    cout<<(isBST(root,NULL,NULL) ? "BST" : "Not BST");
    return 0;
}