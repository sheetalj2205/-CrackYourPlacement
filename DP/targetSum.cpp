/*Approach: it is the same as count of subsets with given diff
In this problem sum is same as diff of the above problem.
We'll assign + or - and try to make their sum as equal to given sum which is similar to obtain a diff of sum of two subsets(separate +ve and -ve nos)
*/

#include<bits/stdc++.h>
using namespace std;

int count(vector<int> arr, int sum);

int main(){
    int n, sum;
    cout<<"Enter size of array and sum ";
    cin>>n>>sum;
    vector<int> arr(n);
    cout<<"Enter array ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
   cout<<count(arr, sum);
}

int count(vector<int> arr, int sum){
    int total = 0, n = arr.size();
    for(int i = 0; i<n; i++){
        total += arr[i];
    }
    /*
    sum(s1) - sum(s2) = diff/sum
    sum(s1) + sum(s2) = sum(array)/total

    on adding both equations
    2*sum(s1) = sum + total
    sum(s1) = sum+total/2
    */
    if(total<abs(sum) || (total+sum)%2!=0){//total of array less than sum(diff of 2 subsets) is never possible and as s1 is sum+total/2 so sum+total should be factor of 2
            return 0;
    }
    int s1 = (sum+total)/2;
    int n = arr.size();
    int dp[n+1][s1+1];

    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i<=sum; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=s1; j++){ //start from 0th column means when sum is 0 because sum of one subset can be 0 also
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][s1];
}
