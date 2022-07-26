/*In the subset sum problem we are only checking whether there are any subset with the given sum or not but in the count of subsets we are supposed to return the count of subsets with the given sum

In subset sum problem we were only checking if the sum is equal to target or not if the sum of subset is equal to target then dp[i][j] = true, we were not checking for further subsets
*/

#include<bits/stdc++.h>
using namespace std;

int count(vector<int> arr, int n, int sum);

int main(){
    int n, sum;
    cout<<"Enter size of array and target sum ";
    cin>>n>>sum;
    vector<int> arr(n);
    cout<<"Enter array ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<count(arr, n, sum);
}

int count(vector<int> arr, int n, int sum){
    int dp[n+1][sum+1];
    /*
    // this is not the right way to initialize the matrix
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0){
                dp[i][j] = 0;
            }
            else if(j == 0){
                dp[i][j] = 1;
            }
        }
    }
    */
   for(int j = 0; j<sum+1; j++){
                dp[0][j] = 0;
        }
        dp[0][0] = 1;
    for(int i = 1; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j]; //only OR changed to +
            }
            else if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][sum];
}
