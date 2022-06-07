
#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& nums);
int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int ans = maxArea(arr);
    cout<<ans;

}
int maxArea(vector<int>& nums) {
    int maxArea = 0;
    int i = 0, j = nums.size()-1;
    while(i<j){
        if(nums[i]<nums[j]){
            maxArea = max(maxArea,nums[i]*(j-i)); //find area with small height bar
            i++;
        }
        else{
            maxArea = max(maxArea,nums[j]*(j-i));
            j--;
        }
    }
    return maxArea;

}
