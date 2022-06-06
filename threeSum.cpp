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
 vector<vector<int>> ans;
 int y;
 int x;
 vector<int> level;
 for(int i = 0; i<arr.size()-3; i++){
    x = 0 - arr[i];
   for(int j = i+1; j<arr.size()-2; j++){
      y = x - arr[j];
     for(int k = j+1; k<arr.size(); k++){
         if(arr[k] == y){
             level.push_back(arr[i]);
             level.push_back(arr[j]);
             level.push_back(arr[k]);
         }
     }
   }
   ans.push_back(level);
   level.clear();
}
 for(int i = 0; i<ans.size(); i++){
     for(int j = 0; j<3; j++){
        cout<<ans[i][j]<<" "<<endl;
     }
       
 }
}
