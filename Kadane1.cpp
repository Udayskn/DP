#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;
  vector<int>num(n);
  for(int i=0;i<n;i++)cin>>num[i];
  vector<int>dp(n);
  dp[0]=num[0];
  int sum=0, k=dp[0];
  sum+=num[0];
  for(int i=1;i<n;i++){
    sum+=num[i];
    if(dp[i-1]<0)dp[i]=num[i];
    else dp[i]=dp[i-1]+num[i];
    k=max(k,dp[i]);
  }
  cout<<k;
}