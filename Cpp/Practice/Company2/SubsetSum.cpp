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
    ll sum;
    cin>>sum;
    bool dp[n+1][sum+1];
    for(ll i=0;i<n+1;i++)
        dp[i][0]=true;
    for(ll i=1;i<sum+1;i++)
        dp[0][i]=false;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=sum;j++)
        {
            if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=dp[i-1][j] | dp[i-1][j-arr[i-1]];
            }
        }
    }
    // for(ll i=0;i<=n;i++)
    // {
    //     for(ll j=0;j<=sum;j++)
    //         cout<<dp[i][j]<<"  ";
    //     cout<<endl;
    // }
    cout<<dp[n][sum]<<endl;
    return 0;
}