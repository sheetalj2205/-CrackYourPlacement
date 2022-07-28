/*Approach: return vector of starting index of substring of s which is anagram to string t
Sliding Window Problem
1) Create two hash tables
2) In first loop store frequency of chars of  both the strings in tables and then compare them by comparing vectors, if they are equal means substring of s starting with index 0 till size of string t is anagram to string t, so push 0 in the ans
3) In second loop starting with the size of string t, decrease freq of char at index i-t.size() in the hash table of string s and increase at s[i]- 'a'index and at any moment where both the vectors are equal add index(i-t.size()+1) in the ans
*/



#include<bits/stdc++.h>
using namespace std;

void allAnagrams(string s, string t);

int main(){
    string s, t;
    cout<<"Enter strings ";
    cin>>s>>t;
    allAnagrams(s, t);
}
void allAnagrams(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<int> ans;
    vector<int> s_vec(26,0);
    vector<int> t_vec(26,0);

    if(n < m){
        return;
    }

    for(int i = 0; i<m; i++){
        s_vec[s[i] - 'a']++;
        t_vec[t[i] - 'a']++;
    }

    if(s_vec == t_vec) ans.push_back(0);

    for(int i = m; i<n; i++){
        s_vec[s[i-m] - 'a']--; /*as in the above loop we have already increased the freq for s[i] till m so with this stat we are simply decreasing the freq of those chars which are at index 0,1.. m-1 in string s;*/
        s_vec[s[i] - 'a']++;

        if(s_vec == t_vec) ans.push_back(i-m+1);
    }
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}
