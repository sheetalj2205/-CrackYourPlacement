#include<bits/stdc++.h>
using namespace std;

string shortestSuperseq(string a, int n, string b, int m);

//worst approach: add the length of both strings that will be your super sequence

int main(){
    string a, b;
    cout<<"Enter strings"<<endl;
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    cout<<shortestSuperseq(a, n, b, m);
}

// LCS approach : add the length of both strings and subtract length of LCS from it to get the shortest super seq
string shortestSuperseq(string a, int n, string b, int m){
    //top-down approach
    int dp[n+1][m+1];
    string ans;
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
    int i = n, j = m; // start from last
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){ //if both chars are equal then push it into string
           ans.push_back(a[i-1]);
           i--;
           j--;
        }
        else if(dp[i-1][j]<dp[i][j-1]){ //if value of j-1 col is greater then push char of b string
            ans.push_back(b[j-1]);
            j--;
        }
        else{ //if value of i-1 row is greater then push char of a string
            ans.push_back(a[i-1]);
            i--;
        }
    }
    while(i>0){ //it is possible that string a is left and string b is reached at 0 then push all left chars of string a in ans
        ans.push_back(a[i-1]);
        i--;
    }
    while(j>0){
        ans.push_back(b[j-1]);
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}
