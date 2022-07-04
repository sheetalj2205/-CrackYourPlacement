//code:
#include<bits/stdc++.h>
using namespace std;

//only 4 lines of code added in recursive approach

int maxProfit(vector<int> weight, vector<int> value, int n, int capacity);
static int t[1000][1000];
int main(){
    int n, w;
    cout<<"Enter size of arrays and max capacity of bag ";
    cin>>n>>w;
    vector<int> weight(n), value(n);
    cout<<"Enter weight of items ";
    for(int i =0; i<n; i++){
        cin>>weight[i];
    }
    cout<<"Enter value of items ";
    for(int i =0; i<n; i++){
        cin>>value[i];
    }
    cout<<maxProfit(weight, value, n, w);
    memset(t, -1, sizeof(t));
}

int maxProfit(vector<int> weight, vector<int> value, int n, int w){
    //base condition
    if(t[n][w] != -1){
        return t[n][w];
    }
    //code of choice diagram
    if(weight[n-1] <= w){ //choice to either include that weight or not
        return t[n][w] = max(value[n-1] + maxProfit(weight, value, n-1, w-weight[n-1]), maxProfit(weight, value, n-1, w));
    }

    //when weight of item is more than capacity
    if(weight[n-1] > w){
       return t[n][w] =  maxProfit(weight, value, n-1, w);
    }
}
