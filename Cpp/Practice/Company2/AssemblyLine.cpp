#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll arr[2][4];
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }
    ll t[2][4];
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<4;j++)
            cin>>t[i][j];
    }
    ll entry[2];
    for(ll i=0;i<2;i++)
        cin>>entry[i];
    ll exit[2];
    for(ll i=0;i<2;i++)
        cin>>exit[i];
    ll dp[2][6];
    dp[0][0]=0;
    dp[1][0]=0;
    dp[0][1]=entry[0]+arr[0][0];
    dp[1][1]=entry[1]+arr[1][0];
    for(ll i=2;i<=4;i++)
    {
        dp[0][i]=min(dp[0][i-1],dp[1][i-1]+t[1][i-1])+arr[0][i-1];
        dp[1][i]=min(dp[1][i-1],dp[0][i-1]+t[0][i-1])+arr[1][i-1];
    }
    dp[0][5]=dp[0][4]+exit[0];
    dp[1][5]=dp[1][4]+exit[1];
    // cout<<arr[0][0]<<" "<<arr[1][0]<<endl;
    // for(ll i=0;i<2;i++)
    // {
    //     for(ll j=0;j<6;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<min(dp[0][5],dp[1][5])<<endl;
}