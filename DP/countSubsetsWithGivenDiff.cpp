/*Approach: we have to calculate no. of subsets with given difference
                        Array
                        /  \
                       S1  S2

 sum(s1) - sum(s2) = diff - (1)
 sum(s1) + sum(s2) = sum(array) - (2)

 on adding both these equations:
 2*sum(s1) = diff + sum(array)
 sum(s1) = diff + sum(array)/2

 as we have diff, sum(array) given in the question, so we'll easily find sum(s1) - sum of one subset 
 Now we just have to find the count of subsets whose sum is sum(s1) - for that simply use approach of countOfSubsets with a given sum problem
*/



#include<bits/stdc++.h>
using namespace std;

void countSubsets(vector<int> arr, int sum);

int main(){
    int n, diff;
    cout<<"Enter size of array and difference ";
    cin>>n>>diff;
    vector<int> arr(n);
    cout<<"Enter array ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int sum = 0, s1;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    s1 = (diff+sum)/2;
    countSubsets(arr, s1);
}

void countSubsets(vector<int> arr, int sum){
    int n = arr.size();
    int dp[n+1][sum+1];

    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i<=sum; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
}
