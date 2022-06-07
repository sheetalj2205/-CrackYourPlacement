
#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;

void mergeSortedArray(vector<int>& arr1 , int n, vector<int>& arr2, int m);

int main(){
    int n,m,c;
    vector<int> arr1(20);
    vector<int> arr2(20);
    cout << "Enter the number of elements in the array ";
    cin >> n;

    cout << "Enter elements of first array" << endl;

    for (c = 0; c < n; c++){
        cin >> arr1[c];
    }
    cout << "Enter the number of elements in the array ";
    cin >> m;
    cout << "Enter elements of second array" << endl;

    for (c = 0; c < m; c++){
       cin >> arr2[c];
    }
    mergeSortedArray(arr1, n, arr2, n);
}
void mergeSortedArray(vector<int>& arr1, int n, vector<int>& arr2, int m){
    int i = m-1, j = n-1, k = m+n-1; //start from last index
        while(i >= 0 && j>=0){
             if(arr1[i] > arr2[j]){ //when arr1 has greater element
                 arr1[k] = arr1[i];
                 i--;
                 k--;
             }
             else {  //when arr2 has greater element
                 arr1[k] = arr2[j];
                 k--;
                 j--;
             }
        }
        while(i>=0){
            arr1[k--] = arr1[i--];
        }
        while(j>=0){
            arr1[k--] = arr2[j--];
        }
    }

    