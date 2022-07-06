/*Identification of Heap problem:
1) k - keyword
2) smallest or largest

For heap use stack of size k

                  Heap
                /     \
            max heap  min heap

When - (k + smallest) = max heap
       (k + largest) = min heap

Heap questions are basically sorting questions, here complexity of sorting i.e nlogn becomes nlogk
How to code?
- use STL
- use top, push and pop
- how to declare heap - priority_queue<int> max; - Max heap
                    priority_queue<int, vector<int>, greater<int>> min; - Min Heap
- when you have to use pairs in heap the use type def

*/
//kth smallest element

/* Heap never gurantees that the element below kth elements are in sorted order, it only gurantees that the element on the top is kth smallest ele.
*/

//code
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> arr, int k);

int main(){
       int n,k;
       cout<<"Enter size of array and k ";
       cin>>n>>k;
       vector<int> arr(n);
       cout<<"Enter array ";
       for(int i = 0; i<n; i++){
              cin>>arr[i];
       }
       cout<<kthSmallest(arr, k);
}
int kthSmallest(vector<int> arr, int k){
       priority_queue<int> max; // for smallest ele create max heap
       for(int i = 0; i<arr.size(); i++){
              max.push(arr[i]);

              if(max.size()>k){
                     max.pop();
              }
       }
       return max.top();
}
