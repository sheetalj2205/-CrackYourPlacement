#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001]; //matrix for memoization
int longestPalindromicSubseq(string word, int n, string word2, int m);
int main(){
    string word;
    cout<<"Enter string"<<endl;
    cin>>word;
    int n = word.size(); 
    string reverseWord(word); //take copy of string word 
    reverse(reverseWord.begin(), reverseWord.end());
    int m  = reverseWord.size();
    memset(t, -1, sizeof(t)); //intialize matrix with -1 for memoization approach
    int ans = longestPalindromicSubseq(word, n, reverseWord, m);
    cout<<ans;
}

int longestPalindromicSubseq(string word, int n, string reverseWord, int m){
    //Recursion approach
    if(n == 0 || m == 0 ){
        return 0; // base condition - minimum valid input
    }
    if(word[n-1] == reverseWord[m-1]){
       return 1  + longestPalindromicSubseq(word, n-1, reverseWord, m-1); // start from the last and if chars are equal then move to second chars in both string, adding one for that equal char
    }
    else{
        return max(longestPalindromicSubseq(word,n, reverseWord, m-1), longestPalindromicSubseq(word, n-1, reverseWord, m));
    }

       // try with tabulation approach also 
}
