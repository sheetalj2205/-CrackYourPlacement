/* How to find it is of DP problem or not?
1) Check there is choice or not
2) Optimal (when you have max, min, largest, smallest)


Problem: there are three types of knapsack problems:
1) Fractional kanpsack (Greedy)
2) 1-0 Knapsack problem
3) Unbounded kanpsack problem

Knapsack problem:
we have given a sack(bag) with fixed weight it can hold
suppose there are two arrays of weight and value of items:
There are 4 items with given weight and values:
int weight[] = {1,2,3,4}
int value[] = {2,4,5,7}
W = 7(max weight)

In knapsack prblm, we need to maximize the profit and the weight of selected items should be equal to given bag weight

In fractional knapsack you can fraction the item then add it in the bag to fill the bag completely - there is no need of dp in this

In 0/1 knapsack either the complete item goes in the bag or not there will be no fraction(multiple occurences not allowed)

In unbounded knapsack there is no bound on the item, you can fill the bag completely with that item.

*/

/*Recursive Approach: First make choice diagram

                      Item1
                     /     \
                  W1<=W     W1>W
                  / \         |
        choice: add  leave   leave


1)Function: return type would be int as max profit is the ans, inputs of the functiona are size of both the arrays, max weight and both arrays of weight and values.

2)Base condition: Always think about smallest valid input
In this case smallest valid inputs are: when max weight and size of arrays are zero.

3)Code for choice diagram

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
    if(weight[n-1] <= capacity){ //choice to either include that weight or not
        return max(value[n-1] + maxProfit(weight, value, n-1, capacity-weight[n-1]), maxProfit(weight, value, n-1, capacity));
    }

    //when weight of item is more than capacity
    if(weight[n-1] > capacity){
        return maxProfit(weight, value, n-1, capacity);
    }
}
