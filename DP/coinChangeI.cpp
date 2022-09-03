//similar to knapsack problem
/*
Here you'll have a array of coins and sum
you have to find max num of ways through which we can get sum 
It is similar to knapsack because you have two options here for each coin either to include it or not
It is unbounded knapsack because you can choose same coin for any num of times
*/

#include<bits/stdc++.h>
using namespace std;

int maxWays(vector<int> coins, int sum);

int main(){
    int n, sum;
    cout<<"enter size of array and sum";
    cin>>n>>sum;
    vector<int> coins(n);
    for(int i = 0; i<n; i++){
        cin>>coins[i];
    }
    cout<<maxWays(coins, sum);
}
int maxWays(vector<int> coins, int sum){
    int n = coins.size();
    int dp[n+1][sum+1];

    for(int  i = 0; i<=n ;i++){
        for(int j = 0; j<=sum; j++){
            dp[0][j] = 0;
            dp[i][0] = 1;
        }
    }
    dp[0][0] = 1 ;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
             if(coins[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
             }
             else{
                dp[i][j] = dp[i-1][j];
             }
        }
    }
    return dp[n][sum];
}
