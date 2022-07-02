#include<bits/stdc++.h>
using namespace std;

/*
Approach: Find LCS of both the strings, as we simply want string a to be entirely present in string b which means length of string a should be equal to length of LCS

*/

bool isMatch(string a, int n, string b, int m);

int main(){
    string a, b;
    cout<<"Enter string [a] to be matched ";
    cin>>a;
    cout<<"Enter string containing string a ";
    cin>>b;
    int n = a.size();
    int m = b.size();
    cout<<isMatch(a, n, b, m);
}
bool isMatch(string a, int n, string b, int m){
    int dp[n+1][m+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            if(i == 0 || j==0){
                dp[i][j] =0;
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
    cout<<dp[n][m]<<endl;
    if(dp[n][m] == n){
        return true;
    }
    return false;
}
