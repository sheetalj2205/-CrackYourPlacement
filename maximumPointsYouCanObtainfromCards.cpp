
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
    int l,r = 0, ans = 0, len = nums.size()-k;
    for(int i = 0; i<nums.size(); i++){
        ans += nums[i];
    }
    int total = ans;
    while(r < nums.size()){
        ans += (nums[r] - nums[l]);
        total = max(total,ans);
        l++;
        r++;
    }
    return total;
}
