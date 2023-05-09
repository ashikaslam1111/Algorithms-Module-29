


class Solution
{
public:
    int change(int amount, vector<int>& coins)
    {
        int num[305];
        int n = coins.size();
        for(int i=1; i<=n; i++)num[i]=coins[i-1];
        const int N=5001;
        long long   int dp[305][N];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=amount; j++)dp[i][j]=0;
        }
        for(int i=0; i<=n; i++)dp[i][0]=1;
        long long int ans1=0;
        long long int ans2=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=amount; j++)
            {
                ans1=dp[i-1][j];
                int c=1;
                long long   int ans2=0;
                while(1)
                {
                    if(j-num[i]*c<0)break;
                    ans2 +=dp[i-1][j-(num[i])*c];
                    c++;
                }
                dp[i][j]=(ans1+ans2);
            }
        }
         return dp[n][amount];
    }

};

//const int N =5005;
//long long int dp[303][N];
//int num[305];
//int solve(int n,int k);
int main()
{

    return 0;
}
//int solve(int n,int k)
//{
//    if(n==0)
//    {
//        if(k==0)return 1;
//        return 0;
//    }
//    if(dp[n][k]!=-1)return dp[n][k];
//    int ans1=0;
//    int ans2=0;
//    int ans=0;
//    ans1 = solve(n-1,k);
//    int i=1;
//    while(1)
//    {
//        if(k-num[n]*i<0)break;
//        ans2 +=solve(n-1,k-num[n]*i);
//        i++;
//    }
//    ans=(ans1+ans2);
//    dp[n][k]=ans;
//    return ans;
//}

