
#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int>& nums, int k);
int main(){
    int n,k;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter no of cards"<<endl;
    cin>>k;
    int ans = maxSum(arr, k);
    cout<<ans;
}

int maxSum(vector<int>& nums, int k){
    int ans = 0;
    int low = 0, high = nums.size()-1;
    while(low<nums.size() && high>=0 && k>0){
        ans += max(nums[low], nums[high]);
        low++;
        high--;
        k--;
    }
    return ans;
}
