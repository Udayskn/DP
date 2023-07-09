#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  vector<int>dpl(n),dpr(n);
  dpl[0]=arr[0];
  dpr[n-1]=arr[n-1];
  int k=dpl[0];
  // running kandanes from both ends and cal normal kadane
  for(int i=1;i<n;i++){
    dpl[i]=max(arr[i],dpl[i-1]+arr[i]);
    k=max(dpl[i],k);
    int j=n-1-i;
    dpr[j]=max(arr[j],dpr[j+1]+arr[j]);
  }
  // checking kadane if ith element is deleted.
  for(int i=1;i<n-1;i++){
    int j=n-1-i;
    k=max(k,dpl[i-1]+dpr[i+1]);
  }
  cout<<k;
}
