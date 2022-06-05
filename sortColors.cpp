#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& arr);
int main(){
     int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    sortColors(arr);
}

void sortColors(vector<int>& arr){
   int low = 0, high = arr.size()-1, mid =0;
   while(mid<=high){
       if(arr[mid] == 0){
           swap(arr[low],arr[mid]);
           low++;
       }
       if(arr[mid] == 2){
           swap(arr[high], arr[mid]);
           high--;
       }
       else{
           mid++;
       }
   }
   for(int i = 0; i< arr.size();i++){
       cout<<arr[i]<<" ";
   }
}
