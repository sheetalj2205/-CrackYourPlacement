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
    void insertInSortedList( int x);
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
void LinkedList:: insertInSortedList(int x){
    Node* start = first;
    Node* temp = NULL;
    while(start && start->data < x){
        temp = start;
        start = start->next;
    }
            Node* node = new Node; //here we are using three pointers try with 2 nodes only
            node->data = x; 
            node->next = temp->next;
            temp->next = node;

}
int main(){
    int arr[] = {1,2,3,4,5};
    LinkedList l(arr, 5);
    l.insertInSortedList(6);
    l.display();
}

