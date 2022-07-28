/*Approach: As it is to find all anagrams problem, only return type changed
*/

#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s, string t);

int main(){
    string s, t;
    cout<<"Enter strings ";
    cin>>s>>t;
    cout<<checkInclusion(s, t);
}
bool checkInclusion(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<int> s_vec(26,0);
    vector<int> t_vec(26,0);

    if(n < m){
        return false;
    }

    for(int i = 0; i<m; i++){
        s_vec[s[i] - 'a']++;
        t_vec[t[i] - 'a']++;
    }

    if(s_vec == t_vec) return true;

    for(int i = m; i<n; i++){
        s_vec[s[i-m] - 'a']--; /*as in the above loop we have already increased the freq for s[i] till m so with this stat we are simply decreasing the freq of those chars which are at index 0,1.. m-1 in string s;*/
        s_vec[s[i] - 'a']++;

        if(s_vec == t_vec) return true;
    }
    return false;
}
