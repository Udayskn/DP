#include<bits/stdc++.h>
using namespace std;
vector<int>v0,v1;
vector<vector<vector<int>>> dp;

int knapsack(int sum0,int sum1,int i){
    // cout<<sum0<<" "<<sum1<<" "<<i<<"\n";
    if(dp[i][sum0][sum1]!=-1)return dp[i][sum0][sum1];
    if(sum0==0 &&sum1==0)return dp[i][sum0][sum1]=0;
    if(i==0)return dp[i][sum0][sum1]=0;
    // either of vol overflow if ith item is added.
    if(sum0<v0[i]||sum1<v1[i])return dp[i][sum0][sum1]=knapsack(sum0,sum1,i-1);
    // max num of items among without(0)/with (1) ith item. i.e 01 knapsack
    return dp[i][sum0][sum1]=max(knapsack(sum0,sum1,i-1),1+knapsack(sum0-v0[i],sum1-v1[i],i-1));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sum0,sum1;cin>>n>>sum0>>sum1;
    v0.resize(n+1,0);v1.resize(n+1,0);
    dp.resize(n+1, vector<vector<int> >(sum0+1, vector<int>(sum1+1,-1)));
    for(int i=1;i<=n;i++){
        string k;
        cin>>k;
        for(int j=0;j<k.size();j++){
            if (k[j]=='0') v0[i]++;
            else v1[i]++;
        }
        // cout<<i<<" "<< v0[i]<<" "<<v1[i]<<"\n";
    }
    cout<<knapsack(sum0,sum1,n);
}