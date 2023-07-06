#include<bits/stdc++.h>
using namespace std;
vector<int>vol,wt;
vector<vector<int>> dp;

int knapsack(int sum,int i){
    // knapsack(sum,i) is already calculated ..
    if(dp[i][sum]!=-1) return dp[i][sum];
    // 0 capacity bag
    if(sum==0)return dp[i][sum]= 0;
    // no items available
    if(i==0)return dp[i][sum]=0;
    // bag  overflow with ith item
    if(sum<vol[i])return dp[i][sum]=knapsack(sum,i-1);
    // max possible with(1) /without(0) ith item i.e 0-1 Knapsack
    return dp[i][sum]=max(knapsack(sum,i-1),wt[i]+knapsack(sum-vol[i],i-1));
}
int main(){
    int n,sum;cin>>n>>sum;
    vol.resize(n+1);wt.resize(n+1);
    dp.resize(n+1,vector<int>(sum+1,-1));
    for(int i=1;i<=n;i++){
        cin>>vol[i]>>wt[i];
    }
    cout<<knapsack(sum,n);
}