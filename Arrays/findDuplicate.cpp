
#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums);
int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    findDuplicate(arr);
}
int findDuplicate(vector<int>& nums) {
        int ans=0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0)  {
                ans = abs(nums[i]); //
            }
            else{
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }
        }
        cout<<ans;
        return ans;
    }

    // doing -1 as array values are starting from 1 (if we don't subtract 1 then we'll never reach index 0), we are jumping from index to index and when we get negative value while jumping we'll return the index which gave us negative value
