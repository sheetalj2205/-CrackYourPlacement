#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestSubseq(string word1,int n, string word2, int m);
int main(){
    string word1, word2;
    cout<<"Enter strings"<<endl;
    cin>>word1;
    cin>>word2;
    int m = word2.size();
    int n = word1.size();
    int ans = longestSubseq(word1, n, word2, m);
    cout<<ans;
}
int longestSubseq(string word1, int n, string word2, int m){
    //first approach - recursion - three important things: 1) base condition 2) choice diagram 3) I/P smallest
    
    if(n == 0 || m == 0){ //base condition i.e. smallest valid input
        return 0;
    }
    else if(word1[n-1] == word2[m-1]){
        return 1 + longestSubseq(word1, n-1, word2, m-1); //if both values/chars are equal then check for next chars, adding 1 because of that one similar char
    }
    return max(longestSubseq(word1, n, word2, m-1), longestSubseq(word1, n-1, word2, m)); //if chars are not equal then this condition takes max value from both the recursions
}
