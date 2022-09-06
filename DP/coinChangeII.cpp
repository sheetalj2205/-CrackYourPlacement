/*Problem: Given a coin array and target sum, you have to find the way in which there is min no of coins because there can be many ways to get the sum from all the coins

coin[] = {1,2,3} sum = 5
Ways:            coins
1) 2+3            2 //ANS
2) 1+1+1+1+1      5
3) 1+2+2          3
4) 1+1+1+2        4
5) 1+1+3          3


INITIALIZATION TWIST:
1) As we want min number of coins to get the sum 
so in first row where coin array has no coin or empty but we want sum from that means we need infinite coins to achieve that because we want min number of coins.
2) In first column where sum is 0 but you have different number of coins in the array, initialization of this column will be with 0 because you want sum 0, so min no. of coins would also be 0.
3) In this quest, you also have to initialize second row when array has only one coin 
*/

#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int> coins, int sum);

int main(){
    int n, sum;
    cout<<"enter size of array and sum";
    cin>>n>>sum;
    vector<int> coins(n);
    for(int i = 0; i<n; i++){
        cin>>coins[i];
    }
    cout<<minCoins(coins, sum);
}
int minCoins(vector<int> coins, int sum){
    int n = coins.size();
    int dp[n+1][sum+1];

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=sum; j++){
            dp[i][0] = 0;
            dp[0][j] = INT_MAX-1; //when size of array is 0 (so it is never possible to get that sum)
        }
    }
    dp[0][0] = INT_MAX-1;
    //fill first row
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(j%coins[0] == 0){
                dp[1][j] = j/coins[0];
            }
            else{
                dp[1][j] = INT_MAX-1;
            }
        }
    }
     for(int i = 2; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(coins[i-1] <= j){
            dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            //take min of both when you didn't take the coin and when you take the coin(when you choose it then add 1 to increase coin count that's why we inserted INT_MAX-1 in the dp because INT_MAX+1 can't store in int)
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[n][sum] == INT_MAX){
        return 0;
    }
    return dp[n][sum];
}
