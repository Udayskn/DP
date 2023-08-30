#include <bits/stdc++.h>
using namespace std;
vector<int>arr,dp;
int main() {
  int n;cin>>n;
  arr.resize(n);dp.resize(n,1);
  for(int i=0;i<n;i++)cin>>arr[i];
  int lds=0;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      // for lis check if arr[i]>arr[j]
      if(arr[i]%arr[j]==0){                                 //longest dividing subsequence
        dp[i]=max(dp[i],dp[j]+1);
      }
    }
    lds=max(lds,dp[i]);
  }
  cout<<lds;
  return 0;

}
