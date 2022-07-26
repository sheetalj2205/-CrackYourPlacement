/* How to find it is similar to knapsack?
Here we have one input array and the target sum, we have to select elements from array to achieve the target
*/

#include<bits/stdc++.h>
using namespace std;

bool targetSum(vector<int> arr, int n, int target);

int main(){
    int n, t;
    cout<<"Enter size of arrays and target ";
    cin>>n>>t;
    vector<int> arr(n);
    cout<<"Enter array ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    bool ans = targetSum(arr, n, t);
    cout<<ans;
}

bool targetSum(vector<int> arr, int n, int target){
    bool dp[n+1][target+1];
    /*
    Here the initialization of matrix will be different:
    no. of rows are representing the size of array and no. of columns representing the target sum, if size of array is 5 and sum is 12 then matrix will be of size dp[6][13].
    1) For first column where sum is zero: If sum is zero then we can have 1,2...5 elements in array and fill the value of first column with true/1 as sum of empty sub set will be zero
    2) For first row where no. of elements in array is 0: If array has no element then sub set can never have sum equals to 1,2,3.....12. So this row will be filled with either false/0. (no value to choose from array)
    */
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<target+1; j++){
            if(i == 0 && j == 0){ //when target sum and elements to select from array both are zero
                dp[i][j] = true;
            }
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
        }
    }
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<target+1; j++){
            if(arr[i-1] <= j){ 
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            if(arr[i-1] > j){
               dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];

}
