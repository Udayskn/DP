#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
string arr1,arr2;
int LCS(int i,int j){
    if(i==-1 ||j==-1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(arr1[i]==arr2[j])return dp[i][j]=1+LCS(i-1,j-1);
    return dp[i][j]= max(LCS(i,j-1),LCS(i-1,j)); 
}
int main(){
    cin>>arr1>>arr2;
    int m=arr1.size(),n=arr2.size();
    dp.resize(m,vector<int>(n,-1));
    cout<<LCS(m-1,n-1);
}


// for LPS i.e pallandromic   reverse the given one string and find LCS of both given and reversed string...
