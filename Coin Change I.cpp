#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int num[13];
        int n = coins.size();
        for(int i=1; i<=n; i++)num[i]=coins[i-1];
        const int N=1e4+5;
        long long   int dp[13][N];
        long long   int inf=1e18;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=amount; j++)dp[i][j]=inf;
        }
        for(int i=0; i<=n; i++)dp[i][0]=0;
        long long   int ans1=1e18;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=amount; j++)
            {
                ans1 = dp[i-1][j];
                int c=1;
                long long   int ans2=1e18;
                while(1)
                {
                    if(j-num[i]*c<0)break;
                    ans2 = min(ans2,c + dp[i-1][j-(num[i])*c]);
                    c++;
                }
                dp[i][j]=min(ans1,ans2);
            }
        }
        if(dp[n][amount]==1e18)return -1;
        return dp[n][amount];
    }
};
int main()
{
    Solution a;
    vector<int>ar= {1,2,5};
    int tar=11;
    cout<<a.coinChange(ar,tar);
    return 0;
}
