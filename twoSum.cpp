#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void twoSum(vector<int>& arr, int target);
int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int t;
    cout<<"Enter target"<<endl;
    cin>>t;
    twoSum(arr,t);
}

void twoSum(vector<int>& arr, int target){
 vector<int> a;
 int y;
 for(int i = 0; i<arr.size()-1; i++){
     y = target - arr[i];
     for(int j = i+1; j<arr.size(); j++){
         if(arr[j] == y){
             a.push_back(i);
             a.push_back(j);
         }
     }
 }
 for(int i = 0; i<a.size(); i++){
     cout<<a[i]<<" ";
 }
}
