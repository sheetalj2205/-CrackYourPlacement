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
    int countNodes();
    int sumOfNodes();
    int maxElement();
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
int LinkedList::countNodes(){
    Node* temp = first;
    int count = 0;
    while(temp){
      count++;
      temp = temp->next;
    }
    return count;
}
int LinkedList::sumOfNodes(){
    Node* temp = first;
    int sum = 0;
    while(temp){
      sum += temp->data;
      temp = temp->next;
    }
    return sum;
}
int LinkedList::maxElement(){
    Node* temp = first;
    int maxi = INT_MIN;
    while(temp){
      if(temp->data > maxi){
          maxi = temp->data;
      }
      temp = temp->next;
    }
    return maxi;
}

int main(){
    int arr[] = {1,2,3,4,5};
    LinkedList l(arr, 5);
    l.display();
    cout<<l.countNodes()<<endl;
    cout<<l.sumOfNodes()<<endl;
    cout<<l.maxElement()<<endl;
}

