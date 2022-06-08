#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void twoSum(vector<int>& arr, int target);
void Print_Vector(vector<int> Vec);

int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int t;
    cout<<"Enter target"<<endl;
    cin>>t;
    twoSum(arr,t);
}

void twoSum(vector<int>& arr, int target){
    vector<vector<int>> ans;
    //check array size if it is less than 4 then
    if(arr.size() < 4){
        return;
    }

sort(arr.begin(),arr.end());
// Two Pointer Approach with two for loops
vector<vector<int>> ans;
for(int i = 0; i<arr.size(); i++){
    if(arr[i-1] == arr[i]){ //fixing first value
        continue;
    }
    for(int j = i+1; j<arr.size(); j++){
        if(arr[j-1] == arr[j]){ //fixing second value
            continue;
        }

        int low = j+1, high = arr.size()-1;
        while(low<high){ //started two pointer approach here
            int sum = arr[i] + arr[j] + arr[low] + arr[high];
            if(sum == 0){
                ans.push_back({arr[i], arr[j], arr[low], arr[high]});
                int val = arr[low];
                while(low<arr.size() && val == arr[low]){
                    low++;
                }
                val = arr[high];
                while(high>0 && val == arr[high]){
                    high--;
                }
            }
            if(sum<0){
                low++;
            }
            else{
                high--;
            }
        }

    }
}


//printing ans
cout << "Set of Vectors: \n";
for (auto it = ans.begin(); it != ans.end(); it++)
{
    Print_Vector(*it);
}
  
}
void Print_Vector(vector<int> Vec)
{
    for (int i = 0; i < Vec.size(); i++) {
        cout << Vec[i] << " ";
    }
    cout << endl;
    return;
}
