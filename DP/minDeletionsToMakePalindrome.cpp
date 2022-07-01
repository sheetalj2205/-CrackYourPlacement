#include<bits/stdc++.h>
using namespace std;

//Approach: we need to find min deletions to make the string palindrome which means if we'll find the longest palindormic subsequence then the length of remaining string would be equal to no. of deletions required to make that string palindrome

int minDeletions(string a, int n, string b, int m);

int main(){
    string a;
    cout<<"Enter string ";
    cin>>a;
    int n = a.size();
    string b = a;
    reverse(b.begin(), b.end());
    int m = b.size();
    int lps = minDeletions(a, n, b, m);
    cout<<"Min. no of deletions: "<<n-lps; // simply subtract lps from length of string
}

int minDeletions(string a, int n, string b, int m){
    //find lps through top down approach
    int dp[n+1][m+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1; j++){
            if(a[i-1] == b [j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];

}
