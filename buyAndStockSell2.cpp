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
        int size = arr.size();
        if(size == 1 || size == 0){
            return;
        }
         
 for(int i = 1; i<arr.size(); i++){ // start loop always from 1 as you need to check previous element always for avoiding runtime error
     if(arr[i-1] < arr[i]){
         ans += arr[i] - arr[i-1];
     }
 }
 cout<<ans<<endl;
}
