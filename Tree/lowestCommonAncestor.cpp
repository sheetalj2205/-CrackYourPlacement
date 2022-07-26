/*
Approach: ancestor which is common of both the nodes
O(n) time - to find the path

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
Node* lowestAncestor(Node* root, Node* p, Node* q);
void preOrder(Node* root);
int main(){
    //create tree
    struct Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    preOrder(root);
    cout<<endl;
    Node* p = root->left;
    Node* q = root->right;
    cout<<lowestAncestor(root, p, q);
}
void preOrder(Node* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

Node* lowestAncestor(Node* node, Node* p, Node* q){
  //base condition
  if(node == NULL|| node == p || node == q){
    return node;
  }
  Node* left = lowestAncestor(node->left, p, q);
  Node* right = lowestAncestor(node->right, p, q);

  if(left == NULL){
    return right;
  }
  else if(right == NULL){
    return left;
  }
  else{ //both left and right are not null i.e both p and q lies under this root
    return node;
  }
}
