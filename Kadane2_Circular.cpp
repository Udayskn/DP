#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;
  vector<int>kid(n);
  for(int i=0;i<n;i++)cin>>kid[i];
  vector<int>dp(n);
  dp[0]=kid[0];
  int sum=0, k=dp[0];
  sum+=kid[0];
  for(int i=1;i<n;i++){
    sum+=kid[i];
    if(dp[i-1]<0)dp[i]=kid[i];
    else dp[i]=dp[i-1]+kid[i];
    k=max(k,dp[i]);
  }
//   cout<<1<<" "<<k<<"\n";
  dp.resize(n,0);
  for(int i=0;i<n;i++){
    kid[i]=(-1)*kid[i];
  }
  dp[0]=kid[0];
  
  int p=dp[0];
//   cout<<"p "<<p<<"\n";
  for(int i=1;i<n;i++){
    dp[i]=max(kid[i],dp[i-1]+kid[i]);
    p=max(p,dp[i]);
  }
//   cout<<"p "<<p<<"\n";
  if(sum>=0)k=max(k,(sum+p));
  cout<<k;
}