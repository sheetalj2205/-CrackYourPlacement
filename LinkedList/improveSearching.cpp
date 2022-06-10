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
    void SearchNode(int target);
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
void LinkedList::SearchNode(int target){
    Node* temp = first;
    Node* q = NULL;
    while(temp){
        if(temp->data == target){ // if the value of data is equal to target then put that node at first place so that next time when you'll search for it less time needed
            q->next = temp->next; 
            temp->next = first; //making that first node
            first = temp;
        }
        q = temp;
        temp = temp->next;
    }
}

int main(){
    int arr[] = {1, 8, 7, 12, 5};
    LinkedList l(arr, 5);
    l.SearchNode(12);
    l.display();
    
}

