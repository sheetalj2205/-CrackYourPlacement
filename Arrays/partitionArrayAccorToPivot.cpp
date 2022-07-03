#include<bits/stdc++.h>
using namespace std;

/* Approach: we need to put smaller elements on the LHS of pivot and greater elements on RHS, so use three loops:
1) to put smaller elements to pivot on LHS
2) to add pivot in the list
3) to add larger elements to pivot on RHS
and maintain one pointer for the index
*/
void pivotArray(vector<int>& arr, int pivot);

int main(){
    int n, pivot;
    cout<<"Enter size of array and pivot ";
    cin>>n>>pivot;
    cout<<"Enter array";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    pivotArray(arr, pivot);
}

void pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int p = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] < pivot){
                ans[p] = nums[i];
                p++;
            }
        }
        for(int i = 0; i<n; i++){
            if(nums[i] == pivot){
                ans[p] = nums[i];
                p++;
            }
        }
        for(int i = 0; i<n; i++){
            if(nums[i] > pivot){
                ans[p] = nums[i];
                p++;
            }
        }
        for(int i = 0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        
    }
