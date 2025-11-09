#include<iostream>
#include<vector>

using namespace std;

int knapsack(int w,vector<int>&val,vector<int>&wt,int n)
{
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main()
{
    vector<int>val={1,2,3};
    vector<int>wt={4,5,1};
    int w=4;
    int n=val.size();
    int ans=knapsack(w,val,wt,n);
    cout<<"Max profit is:"<<ans;
    return 0;
}