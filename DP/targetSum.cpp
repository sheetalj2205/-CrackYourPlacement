/* How to find it is similar to knapsack?
Here we have one input array and the target sum, we have to select elements from array to achieve the target
*/

#include<bits/stdc++.h>
using namespace std;

int targetSum(vector<int> arr, int n, int target);

int main(){
    int n, t;
    cout<<"Enter size of arrays and target ";
    cin>>n>>t;
    vector<int> arr(n);
    cout<<"Enter array ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    cout<<targetSum(arr, n, t);
}

int targetSum(vector<int> arr, int n, int target){
    //Recursive approach
    //base condition
    if(n == 0 || target == 0){
        return 0;
    }
    //choice diagram
    if(arr[n-1] <= target){
        return max(targetSum(arr, n-1, target-arr[n-1]), targetSum(arr, n-1, target));
    }
    if(arr[n-1] > target){
        return targetSum(arr, n-1, target);
    }
}
