/*Approach: Find min subset sum difference
In equal partition sum problem - sum of both the subsets are equal which means their abs diff was zero
                   
                   Array
                   /  \
                  S1  S2

min abs diff = S2-S1 
but S2 can be replaced by range - S1, range is the total sum of array. So sum = range - 2S1(range - S1 - S1)
and our task is to minimize range-2S1 and S1 always lies halfway of range (filter out the elements in range which cannot be possible as a sum)
IMP: hence concluded that two subsets are not required to find min abs diff
*/

#include<bits/stdc++.h>
using namespace std;

int minDifference(vector<int> arr, int sum);
void subsetSum(vector<int> arr, int sum);
int main(){
    int n;
    cout<<"Enter size of array ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    subsetSum(arr, sum);
}

void subsetSum(vector<int> arr, int sum){
    //use this function to find the table
    int n = arr.size();
    bool dp[n+1][sum+1];
    //intialize dp
    for(int j = 0; j<sum+1; j++){
             dp[0][j] = false;
    }
    dp[0][0] = true;
    //simply use top-down approach to fill the dp
    for(int i = 1; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(arr[i-1] <= j){ //if arr[i-1] is less than or equal to sum then only you can take that ele in subset
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }

        }
    }
    //intialize vector to store all the elements till half of the sum of bottom most row which contains all the ele of array
    vector<int> vec;
    for(int i = 0; i<(sum+1)/2; i++){
        if(dp[n][i] == true){ //push only those values of sum which are possible i.e true
            vec.push_back(i);
        }
    }
    int m = INT_MAX;
    //to find the min absolute diff subtract 2*S1 from sum as (range- S1 - S2)
    for(int i = 0; i<vec.size(); i++){
        m = min(m, sum-2*vec[i]);
    }
    cout<<m;
}
