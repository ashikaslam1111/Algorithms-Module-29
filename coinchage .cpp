#include<bits/stdc++.h>
using namespace std;
const int N =1e4+5;
int dp[13][N];
int num[13];
int solve(int n,long long k);
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    long long target; // modify target to long long
    cin>>n>>target;
    for(int i=1; i<=n; i++)
        cin>>num[i];
    cout<<solve(n,target);
    return 0;
}
int solve(int n,long long k) // modify k to long long
{
    if(n==0)
    {
        if(k==0)return 0;
        return 1e9;
    }
    if(dp[n][k]!=-1)return dp[n][k];
    int ans1=1e9;
    int ans2=1e9;
    int ans=1e9;
    ans1 = solve(n-1,k);
    int i=1;
    while(1)
    {
        if(k-num[n]*i<0)break;
        ans2 = min(ans2,i+solve(n-1,k-num[n]*i));
        i++;
    }
    ans=min(ans1,ans2);
    dp[n][k]=ans;
    return ans;
}
