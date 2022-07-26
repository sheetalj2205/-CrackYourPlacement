/*
Approach: Use property of binary search tree that all the elements greater than root lies on right side and smaller elements on left side
*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;

  Node(int val){
    data = val;
    left = right = NULL;
  }
};
Node* lowestCommonAncestor(Node* root, Node* p, Node* q);
void preOrder(Node* root);
int main(){
    //create tree
    struct Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    preOrder(root);
    cout<<endl;
    Node* p = root->left;
    Node* q = root->right;
    cout<<lowestCommonAncestor(root, p, q);
}
void preOrder(Node* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

Node* lowestCommonAncestor(Node* node, Node* p, Node* q){
  //if node->val is less than both the q->val and p->val then surely both the roots will lie on right side of tree
  if((node->data < p->data) && (node->data < q->data)){
    return lowestCommonAncestor(node->right, p, q);;
  }
  //if node->val is greater than both the q->val and p->val then surely both the roots will lie on left side of tree
  else if((node->data > p->data) && (node->data > q->data)){
    return lowestCommonAncestor(node->left, p, q);;
  }
    return node; //return node in the end 
}
