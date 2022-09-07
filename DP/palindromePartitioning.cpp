/*Approach: you have given a string and you need to partition it in such a way that every string in that partition is palindrome and you want min partitions . In the worst case it is possible that you have partition after every char = n-1 partitions.

Format: same as MCM
*/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
int solve(string s, int i, int j){
      if(i>=j || isPalindrome(s, i, j)){ //when string has only one letter or no letter
            return 0;
        }
        int mn = INT_MAX, temp;
        for(int k = i; k<j; k++){
            temp = solve(s,i,k) + solve(s, k+1, j) + 1;//adding 1 for the partition itself
            mn = min(mn, temp);
        }
        return mn;
}
int main(){
    string s="ababbbabbababa";
    int n = s.size();
    cout << "Min cuts needed for " <<
      "Palindrome Partitioning is " << solve(s, 0, n-1)<<endl;
    return 0;
}
