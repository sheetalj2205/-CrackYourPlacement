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

    public:
    LinkedList(){
        first = NULL;
    };
    LinkedList(int arr[], int n);
    void display();
    void insert(int data);
    void insertAtPos(int data, int pos);
};
LinkedList:: LinkedList(int arr[], int n){
    Node* last, *temp;
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

void LinkedList::insert(int val){
   // inserting node at the starting of LinkedList
    Node* node = new Node;
    node->data = val;
    node->next = first;
    first = node;

}
void LinkedList::insertAtPos(int val, int pos){
    Node* temp = first; //temp is at first position
    for(int i = 1; i<pos-1 && temp; i++){
        temp = temp->next; //reach upto pos-1 so you can add node at pos and also check p is not null
    }
    if(temp){
        Node* node = new Node;
        node->data = val;
        node->next = temp->next;
        temp->next = node;

    }

}
int main(){
    int arr[] = {1, 8, 7, 12, 5};
    LinkedList l(arr, 5);
    // l.insert(3);
    // l.display();
    l.insertAtPos(10, 8);
    l.display();
    
}

