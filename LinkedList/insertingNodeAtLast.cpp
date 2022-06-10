#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
class LinkedList{
    private:
    Node* first;
    Node* last;

    public:
    LinkedList(){
        first = NULL;
    };
    LinkedList(int arr[], int n);
    void display();
    void insert(int data);
    void insertAtLast(int data);
};
LinkedList:: LinkedList(int arr[], int n){
    Node *temp;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i<n; i++){
         temp = new Node;
         temp->data = arr[i];
         temp->next = NULL;
         last->next = temp;
         last = temp;

    }

}
void LinkedList::display(){
    Node* t = first;
    cout<<"Linked List is"<<endl;
    while(t){
        cout<<t->data<< " ";
        t = t->next;
    }
    cout<<endl;
}

void LinkedList::insertAtLast(int val){
    Node* node = new Node;
    node->data = val;
    node->next = NULL;
    if(first == NULL){
        last = first = node;
    }
    else{
    last->next = node;
    last = node;
    }

}

int main(){
    int arr[] = {1, 8, 7, 12, 5};
    LinkedList l(arr, 5);
    l.insertAtLast(6);
    l.display();
}

