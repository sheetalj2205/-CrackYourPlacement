//same as unbounded knapsack (only variation in the way of asking a question)

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> price, int maxLen);

int main(){
    int n, maxLen;
    cout<<"enter size of price array and max len of rod ";
    cin>>n>>maxLen;
    vector<int> arr(n);
    cout<<"enter price of each piece ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxProfit(arr, maxLen);
}
int maxProfit(vector<int> price, int maxLen){
    int n = price.size();
    int dp[n+1][maxLen+1];
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=maxLen; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    vector<int> length(n);
    for(int i = 0; i<n; i++){
        length[i] = i+1;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=maxLen; j++){
            if(length[i-1] <= j){
                 dp[i][j] = max(price[i-1] + dp[i-1][j - length[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][maxLen];
}
