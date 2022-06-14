#include <iostream>
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
    void deleteNode(int pos);
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

}

void LinkedList::deleteNode(int pos){
    Node* p,*q;
    if(pos == 1){
        p = first; // assign first node to p
        first = first->next; //point first to next node of first
        delete p;
    }
    if(pos > 1){
        p = first; //start from first
        q = NULL;
        for(int i = 0; i < pos-1; i++){ //go upto pos-1 as starting from 0
            q = p;
            p = p->next;
        }
        q->next = p->next; //link q to next node of p
        delete p;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    LinkedList l(arr, 5);
    l.deleteNode(1);
    l.display();
}

