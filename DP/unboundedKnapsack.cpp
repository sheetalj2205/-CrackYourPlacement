/*Unbounded Knapsack: Rod cutting, coin change 1, coin change 2
In 0/1 knapsack we have two arrays of item and weight, and we decide only once whether to take that item or not, we never come back to that again.
In unbounded knapsack, we can take the same item multiple times but if you didn't choose the item means it got processed and you never come back on it again but if you chose the item then you can select it multiple times
*/

//code:
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> weight, vector<int> value, int n, int capacity);

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
}

int maxProfit(vector<int> weight, vector<int> value, int n, int capacity){
    //base condition
    if(n == 0 || capacity == 0){
        return 0;
    }
    //code of choice diagram
    if(weight[n-1] <= capacity){ //choice to either include that weight or not(if included you can take that item again)
        return max(value[n-1] + maxProfit(weight, value, n, capacity-weight[n-1]), maxProfit(weight, value, n-1, capacity));
    }

    //when weight of item is more than capacity
    if(weight[n-1] > capacity){
        return maxProfit(weight, value, n-1, capacity);
    }
}
