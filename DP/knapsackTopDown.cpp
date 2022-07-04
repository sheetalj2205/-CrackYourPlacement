//code:
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> weight, vector<int> value, int n, int capacity);

int main(){
    int n, w;
    cout<<"Enter size of arrays and max capacity of bag ";
    cin>>n>>w;
    vector<int> weight(n), value(n);
    cout<<"Enter weight of items ";
    for(int i =0; i<n; i++){
        cin>>weight[i];
    }
    cout<<"Enter value of items ";
    for(int i =0; i<n; i++){
        cin>>value[i];
    }
    cout<<maxProfit(weight, value, n, w);
}

int maxProfit(vector<int> weight, vector<int> value, int n, int w){
    //top-down approach
    int dp[n+1][w+1];
    /*why this intialization is imp?
    base condition of recursive code is intialization here
    */
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j< w+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    //replace all n,m by i and j
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j< w+1; j++){
            if(weight[i-1] <= j){
            dp[i][j] = max(value[i-1] + dp[i-1][j - weight[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
