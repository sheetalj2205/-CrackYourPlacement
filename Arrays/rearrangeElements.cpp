#include<bits/stdc++.h>
using namespace std;

//Approach: take two pointers for pos and neg value and increase them with 2 whenever you find any neg or pos value as array should have alternative pos and neg values
void rearrangeArray(vector<int>& arr);

int main(){
    int n;
    cout<<"Enter size of array ";
    cin>>n;
    cout<<"Enter array";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    rearrangeArray(arr);
}
void rearrangeArray(vector<int>& nums){
    vector<int> v(nums.size());
        int p = 0, n = 1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > 0){
                v[p] = nums[i];
                p+=2;
            }
            else{
                v[n] = nums[i];
                n+=2;
            }
        }
        for(int i = 0; i<nums.size(); i++){
            cout<<v[i]<<" ";
        }
}
