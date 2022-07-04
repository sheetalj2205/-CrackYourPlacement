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
//  set<vector<int>> ans;
 sort(arr.begin(),arr.end());
//  // brute force approach 
//  // SC = O(M) (M distinct triplets) and TC = O(N^3)*log M (log M = to insert distinct triplets in set)
//  for(int i = 0; i<arr.size()-1; i++){
//    for(int j = i+1; j<arr.size()-1; j++){
//      for(int k = j+1; k<arr.size(); k++){
//          if(arr[i] + arr[j]+ arr[k] == 0){
//              ans.insert({arr[i], arr[j], arr[k]});
//          }
//      }
//    }
// }

// //HashMap Approach 
// unordered_map<int, int> mp;

// for(int i = 0; i<arr.size(); i++){
//     mp[arr[i]]++;
// }

// for (int i = 0; i<arr.size()-1; i++){
//     mp[arr[i]]--;
//     for(int j = i+1; j<arr.size()-1; j++){
//         mp[arr[j]]--;
//         int c = arr[i]+arr[j]; 
//         if(mp.count(-c)>0){
//             ans.insert({arr[i], arr[j], -c});
//         }
//         mp[arr[j]]++;

//     }
//     mp[arr[i]]++;
// }

// Two Pointer Approach - most optimized
vector<vector<int>> ans;
for(int i  = 0; i<arr.size(); i++){
    if(i>0 && arr[i] == arr[i-1]){
        continue; //skip arr[i] if its value is same as previous one
    }
    int low = i+1, high = arr.size()-1;
    while(low<high){
        int sum = arr[i]+ arr[low]+ arr[high];
        if(sum == 0){
            ans.push_back({arr[i], arr[low], arr[high]});
            int value = arr[low];
            while(low<arr.size() && value == arr[low]){
              low++; //skip similar low values
            }
            value = arr[high];
            while(high>0 && value == arr[high]){
              high--; //skip similar high values
           }
        }
        else if(sum>0){
            high--;
        }
        else{
            low++;
        }

    }
}


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
