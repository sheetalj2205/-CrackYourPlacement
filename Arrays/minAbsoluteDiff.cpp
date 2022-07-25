/*
Sort the array then find min absolute difference of the array then put those consecutive elements in array which has the min abs. diff.
*/
#include<bits/stdc++.h>
using namespace std;

void minimumAbsDifference(vector<int>& arr);

int main(){
    int n;
    cout<<"Enter size of array ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    minimumAbsDifference(arr);
}

void minimumAbsDifference(vector<int>& arr) {
        //O(n) time
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for(int i = 1; i<arr.size()-1; i++){
            int d = arr[i+1] - arr[i];
            diff = min(d, diff);
        }
        for(int i = 0; i<arr.size()-1; i++){
            int d = arr[i+1] - arr[i];
            if(d == diff){
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        for(int i =0; i<ans.size(); i++){
            for(int j = 0; j<2; j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
