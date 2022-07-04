#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void setMatrixZero(vector<vector<int>>& arr);
int main(){
    int m;
    cout<<"Enter no of rows size"<<endl;
    cin>>m;
    int n;
    cout<<"Enter no of columns size"<<endl;
    cin>>n;
    vector<vector<int>> arr(m, vector<int>(n));
    cout<<"Enter array"<<endl;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    setMatrixZero(arr);
}

void setMatrixZero(vector<vector<int>>& arr){
    int m = arr.size();
    int n = arr[0].size();
    vector<int> row (m,1); //create row for the row where zero is coming
    vector<int> col(n,1); //create col for the col where zero is coming
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(arr[i][j] == 0){ //find where zero is coming in matrix
                row[i] = 0; //put zero in row vector at ith value of matrix[i] =0
                col[j] = 0; //put zero in col vector at jth value of matrix[j] =0
            }
        }
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(row[i] == 0 || col[j] == 0){ //iterate row and col vectors and where they are zero replace that with zero in matrix
                arr[i][j] = 0;
            }
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout<< arr[i][j] << " ";
        }
    }

}
