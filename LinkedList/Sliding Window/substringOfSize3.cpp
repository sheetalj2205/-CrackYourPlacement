#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int subStringOfSize3(string s);
int main(){
    string s;
    cout<<"Enter string"<<endl;
    cin>>s;
    int ans = subStringOfSize3(s);
    cout<< ans;
}

int subStringOfSize3(string s){
    int i = 0, j =0 , count = 0;
    while(j < s.size()){
        if(j-i+1 < 3){
            j++;  //create window of size 3
        }
        else if (j-i+1 == 3){ // when window size is 3 then check for all the 3 values that they are equal or not
            if((s[i] != s[i+1] && s[i+1] != s[i+2]) && (s[i+1] != s[i] && s[i+1] != s[i+2]) && (s[i+2] != s[i] && s[i+2] != s[i+1]) ){
                count++;
            }
            i++; //if all the three values are not distinct then increase i
            j++; //similarly increase j to create window of size 3
        }
    }
  return count;

}
