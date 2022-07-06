#include<bits/stdc++.h>
using namespace std;

void kLargest(vector<int> arr, int k);

int main(){
       int n,k;
       cout<<"Enter size of array and k ";
       cin>>n>>k;
       vector<int> arr(n);
       cout<<"Enter array ";
       for(int i = 0; i<n; i++){
              cin>>arr[i];
       }
       kLargest(arr, k);
}
void kLargest(vector<int> arr, int k){
    //first approach should be of sorting
     priority_queue<int, vector<int>, greater<int>> min; //take min heap for largest elements
     for(int i = 0; i<arr.size(); i++){
        min.push(arr[i]);
        if(min.size() > k){
            min.pop();
        }
     }
     while(min.size() > 0){
        cout<<min.top()<<" ";
        min.pop();
     }
}
