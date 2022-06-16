#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string word1,int n, string word2, int m);
int main(){
    string word1, word2;
    cout<<"Enter strings"<<endl;
    cin>>word1;
    cin>>word2;
    int m = word2.size();
    int n = word1.size();
    int ans = longestCommonSubstring(word1, n, word2, m);
    cout<<ans;
}
int longestCommonSubstring(string word1,int n, string word2, int m){
    int dp[n+1][m+1];
    int result;
    for(int i = 0; i<n+1; i++){
        for(int j  = 0; j<m+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i<n+1; i++){
        for(int j  = 1; j<m+1; j++){
            if(word1[i-1] == word2[j-1]){
               dp[i][j] = 1 + dp[i-1][j-1];
               result = max(result, dp[i][j]);
            }
            else{
                dp[i][j]  = 0;
            }
        }
    }
    return result;
    //for palindrome string take reverse of input string
}
