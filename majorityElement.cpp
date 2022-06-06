#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& arr);
int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int ans = majorityElement(arr);
    cout<<ans;
}

int majorityElement(vector<int>& arr){
 int size = arr.size();
 if(size == 1) return arr[0];
 int me = floor(size/2); //take floor value after doing half of size
 unordered_map<int,int> num; // map will store frequency of each element in arr
 for(int i = 0; i<size; i++){
     num[arr[i]]++; // increase value of each ele in map
     if(num[arr[i]] > me){ //when it is greater than size/2 stop it and return that element
         return arr[i];
         break;
     }
 }
 return -1;
}
