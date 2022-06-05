
#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;

void findDuplicate(vector<int>& nums);
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
void findDuplicate(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0)  {
                ans.push_back(abs(nums[i])); //add duplicate number
            }
            else{
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }
        }
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }

    // doing -1 as array values are starting from 1 (if we don't subtract 1 then we'll never reach index 0), we are jumping from index to index and when we get negative value while jumping we'll return the index which gave us negative value
