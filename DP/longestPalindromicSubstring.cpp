#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void longestPalindromicSubstring(string word1,int n, string word2, int m);
int main(){
    string word1;
    cout<<"Enter strings"<<endl;
    cin>>word1;
    int n = word1.size();
    string word2(word1);
    reverse(word2.begin(), word2.end());
    int m = word2.size();
    longestPalindromicSubstring(word1, n, word2, m);
}

void longestPalindromicSubstring(string word1,int n, string word2, int m){
    int dp[n+1][m+1];
    int result = 0, endIndex=0;
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
               if(dp[i][j] > result){
                   result = dp[i][j];
                   endIndex = i;

               }
            }
            else{
                dp[i][j]  = 0;
            }
        }
    }
    string ans = word1.substr(endIndex-result,result);
    cout<<ans;
    
}
