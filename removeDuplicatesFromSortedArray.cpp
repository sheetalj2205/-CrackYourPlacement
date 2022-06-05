#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(vector<int>& arr);
int main(){
     int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    removeDuplicates(arr);
}

void removeDuplicates(vector<int> &arr){
    int size = arr.size();
    if(size == 1 || size == 0){
        return;
    }
    int j = 0;
    for(int i = 1; i<size; i++){
        if(arr[i] != arr[j]){
            j++;
            arr[j] = arr[i];
        }
       
    }
    cout<<j+1;
}
