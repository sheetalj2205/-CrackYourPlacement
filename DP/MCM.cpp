/*
Format of all the MCM problems: Given a array or string with first index "i" and last index "j" and you have to break it at a index "k";
- Then find the temp ans from i to k and k+1 to j
- Then to find the ans apply some function on this temp answers


Problem statement:
- A1, A2, A3, A4 - matrices are given
- arr = [10,20,20,40] - storing dimensions of the matrices
- You have to do the parenthesisation of the matrices in such a way that the cost of multiplication would be minimum.
- ((A1, A2)(A3, A4)), A1(A2(A3,A4)) etc.

How to find the dimension of matrix?
- Given arr: [10, 40, 20, 30, 10], n=5
- No. of matrices = n-1 = 4
- dimension of matrix A1 = 10*40
                      A2 = 40*20.. so on
- General format: Ai = arr[i-1]*arr[i]

Format: same as MCM 
1) Find i,j
2) Find base condition
3) Find k (loop scheme)
4) calculate ans from temp ans
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int i, int j);

int main(){
    int n;
    cout<<"enter size of array ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<solve(arr, 1, n-1);
}

int solve(vector<int> arr, int i, int j){
    if(i>=j){
        return 0;
    }//base condition if i==j means there is only one ele in array and for finding dimension we need atleast two elements, if i>j means no ele.
    int min = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int temp = solve(arr, i, k) + solve(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];

        if(temp<min){
            min = temp;
        }
    }
    return min;
}
