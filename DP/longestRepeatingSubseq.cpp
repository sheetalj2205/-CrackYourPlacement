#include<bits/stdc++.h>
using namespace std;

string longestSubseq(string a, int n, string b, int m);

int main(){
    string a;
    cout<<"Enter string ";
    cin>>a;
    int n = a.size();
    string b = a;
    int m = b.size();
    cout<<longestSubseq(a, n, b, m);
}
string longestSubseq(string a, int n, string b, int m){
    int dp[n+1][m+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            if(i == 0 || j ==0){
                dp[i][j] = 0;
            }
        }
    }
    int result = 0, endRow, endCol ;
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1; j++){
                if(a[i-1] == b[j-1] && i!=j){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
    }
}
//this code is not working of printing the repeating subsequence
string ans;
int i = n, j = m;
while(i>0 && j>0){
    if(dp[i][j] == dp[i-1][j-1] + 1){
        ans.push_back(a[i]);
        i--;
        j--;
    }
    if(dp[i][j] < dp[i-1][j]){
        i--;
    }
    else{
        j--;
    }
}
reverse(ans.begin(), ans.end());
return ans;
}
