#include<bits/stdc++.h>
using namespace std;

int shortestSuperseq(string a, int n, string b, int m);

//worst approach: add the length of both strings that will be your super sequence

int main(){
    string a, b;
    cout<<"Enter strings"<<endl;
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    int lcs = shortestSuperseq(a, n, b, m);
    cout<<m+n-lcs;
}

// LCS approach : add the length of both strings and subtract length of LCS from it to get the shortest super seq
int shortestSuperseq(string a, int n, string b, int m){
    /*recursion approach
    if(n == 0 || m == 0){
        return 0;
    }
    if(a[n-1] == b[m-1]){
        return 1 + shortestSuperseq(a, n-1, b , m-1);
    }
    return max(shortestSuperseq(a, n-1, b, m), shortestSuperseq(a, n, b, m-1));*/

    //top-down approach
    int dp[n+1][m+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }

    }
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

    }
    return dp[n][m];

}
