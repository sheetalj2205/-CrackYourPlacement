#include<bits/stdc++.h>
using namespace std;

//Approach: a number can be divided into three numbers if it is divisible by 3

vector<long long> sumOfThree(long long num);

 int main(){
    long long n;
    cout<<"Enter number ";
    cin>>n;
    sumOfThree(n);
 }
vector<long long> sumOfThree(long long num) {
        long long x = 0;
        if(num%3 == 0){
            x =  num/3; //find the quotient
            return {x-1,x,x+1};
        }
        return {};     
    }
