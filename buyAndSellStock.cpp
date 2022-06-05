#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sellStock(vector<int>& arr);
int main(){
     int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    sellStock(arr);
}

void sellStock(vector<int>& arr){
 int ans = 0;
 int j = 0;
 for(int i = 1; i<arr.size(); i++){
     if(arr[i]-arr[j]>ans){
         ans = arr[i] - arr[j];
     }
     else if(arr[i] - arr[j]<0){
         j = i;
     }
 }
 cout<<ans<<endl;
}
