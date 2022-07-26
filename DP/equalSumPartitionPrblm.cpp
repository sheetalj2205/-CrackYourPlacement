/*Approach: Similar to subset sum problem:
1) As we have to divide the array in equal sum partition which means the sum of all elements of array should be even then only it is possible to divide them in equal sum, if the sum of array is odd then it is never possible to find the equal sum arrays.
2) Half the sum of array elements will be the target sum of one partition array.
3) If the sum of subset of one array is sum/2 then the rest elements will be the second array.
*/

#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& arr);

int main(){
    int n;
    cout<<"Enter size of array ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<canPartition(arr);
}
bool canPartition(vector<int>& arr) {
    int n = arr.size();
    int target = 0;
    for(int i = 0; i<n; i++){
        target += arr[i];
    }
    if(target%2 != 0){
        return false;
    }
    int sum = target/2;
    bool dp[n+1][sum+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
        }
    }
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(arr[i-1] <= j){ 
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            if(arr[i-1] > j){
               dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
        
    }
