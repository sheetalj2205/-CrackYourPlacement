#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& arr);
int main(){
     int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    moveZeroes(arr);
}
void moveZeroes(vector<int>& arr){
    int j = 0;
    for(int i  = 1; i<arr.size(); i++){
        if(arr[j] == 0 && arr[i]!=0){ // if first element is zero and second if non zero then swap then and increase both i and j
           swap(arr[i], arr[j]);
           j++;
        }
        if(arr[j]!=0){ // if first element is not zero then increase i and j in this case also
            j++;
        }
        //else in the case where both arr[i] and arr[j] are zero then increase only i
    }
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}
