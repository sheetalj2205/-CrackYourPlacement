#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void subArraySum(vector<int>& arr, int k);
int main(){
    int n,k;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter value of K"<<endl;
    cin>>k;
    subArraySum(arr,k);
}

void subArraySum(vector<int>& arr, int k){
   int ans = 0, sum = 0, rem = 0;
   unordered_map<int, int> m;
   m[0]++; //storing remainder and its frequency

   for(int i = 0; i<arr.size(); i++){
       sum += arr[i];
       rem = sum%k;
       if(rem<0) rem += k; //if rem is negative then add k to it
       if(m.count(rem) > 0){
           ans+= m[rem]; //add frequency of that rem to ans
       }
       m[rem]++;

   }


 cout<<ans<<endl;
}
