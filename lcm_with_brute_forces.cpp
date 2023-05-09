#include<bits/stdc++.h>
using namespace std;
vector<char>a;
vector<char>b;
int solv(int i,int j);
int dp[1000][1000];
int main()
{
    memset(dp,-1,sizeof(dp));
    a= {'a','z','y'};
    b= {'a','c','z','0'};
    cout<<solv(0,0);
    return 0;
}
int solv(int i,int j)
{
    if(i==a.size()|| j==b.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(a[i]==b[j]) return dp[i][j] = 1+solv(i+1,j+1);
    int ansx =solv(i,j+1);
    int ansy =solv(i+1,j);
    return dp[i][j] =max(ansx,ansy);

}
