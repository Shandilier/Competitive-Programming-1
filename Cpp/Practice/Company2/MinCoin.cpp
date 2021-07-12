#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll k;
    cin>>k;
    ll dp[n+1][k+1];
    for(ll i=0;i<=n;i++)
        dp[i][0]=0;
    for(ll j=1;j<=k;j++)
        dp[0][j]=INT_MAX;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=k;j++)
        {
            if(j<arr[i-1])
                dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=min(dp[i][j-arr[i-1]]+1,dp[i-1][j-arr[i-1]]+1);
            }
        }
    }
    // for(ll i=0;i<=n;i++)
    // {
    //     for(ll j=0;j<=k;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    ll ans=INT_MAX;
    for(ll i=0;i<=n;i++)
        ans=min(ans,dp[i][k]);
    if(ans==INT_MAX)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}