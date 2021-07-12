#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    ll matrix[n][n];
    ll coin[n][n];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>matrix[i][j];
            cin>>coin[i][j];
        }
    }
    ll maxm=0;
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    ll flag1=0,flag2=0;
    dp[0][0]=coin[0][0];
    for(ll i=1;i<n;i++)
    {
        if(matrix[0][i]==-1)
        {
            flag1=1;
        }
        if(flag1==0)
        {
            dp[0][i]=dp[0][i-1]+coin[0][i];
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(matrix[i][0]==-1)
        {
            flag2=1;
        }
        if(flag2==0)
        {
            dp[i][0]=dp[i-1][0]+coin[i][0];
        }
    }
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<n;j++)
        {
            if(matrix[i][j]==-1)
            {
                dp[i][j]=-1;
            }
            else
            {
                if(dp[i-1][j]!=-1)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+coin[i][j]);
                }
                if(dp[i][j-1]!=-1)
                {
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+coin[i][j-1]);
                }
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}