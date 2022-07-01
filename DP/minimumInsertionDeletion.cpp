#include<bits/stdc++.h>
using namespace std;

/* Approach: Find Lcs of both the strings then as we need to convert string a to string b, subtract length of lcs(common part of both strings) from n to find no of deletions and to find no of insertions subtract lcs from m
*/
int minOperations(string a, int n, string b, int m);

int main(){
    string a, b;
    cout<<"Enter strings"<<endl;
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    int lcs = minOperations(a, n, b, m);
    cout<<"no. of deletions "<<n-lcs<<endl;
    cout<<"no. of insertions "<<m-lcs<<endl;

}

int minOperations(string a, int n, string b, int m){
    int dp[n+1][m+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            if(i == 0 || j ==0){
                dp[i][j] = 0;
            }
        }
    }
     for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];  

}
