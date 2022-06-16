#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void longestSubseq(string word1,int n, string word2, int m);
int main(){
    string word1, word2;
    cout<<"Enter strings"<<endl;
    cin>>word1;
    cin>>word2;
    int m = word2.size();
    int n = word1.size();
    longestSubseq(word1, n, word2, m);
}
void longestSubseq(string word1, int n, string word2, int m){
    // top-down approach DP
    int dp[n+1][m+1];
    for(int i = 0; i<n+1; i++){ //use these loops for base condition of recursive solution i.e when either length of word1 or word2 is zero
        for(int j  = 0; j<m+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i<n+1; i++){
        for(int j  = 1; j<m+1; j++){
            if(word1[i-1] == word2[j-1]){ //check if chars are equal or not
                dp[i][j] = 1 + dp[i-1][j-1]; // if they are equal add one to the previous value of dp[i][j]      
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]); //similar to recursive solution when chars are not equal, check one by one(take first word whole leaving second word's last or first char and vice versa ) and take max from them
            }
        }
    }
    int i  = n, j = m;
    string ans;
    while(i>0 && j>0){
        if(word1[i-1] == word2[j-1]){
          ans.push_back(word1[i-1]);
          i--;
          j--;
        }
        if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
}
