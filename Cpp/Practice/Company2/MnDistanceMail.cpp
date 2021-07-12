#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll house[n];
    for(ll i=0;i<n;i++)
        cin>>house[i];
    sort(house,house+n);
    ll k;
    cin>>k;
    ll OneMailBox[n][n];
    memset(OneMailBox,0,sizeof(OneMailBox));
    for(ll k=2;k<=n;k++)
    {
        for(ll i=0;i<n-k+1;i++)
        {
            ll j=i+k-1;
            OneMailBox[i][j]=house[j]-house[i]+OneMailBox[i+1][j-1];
        }
    }
    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<n;j++)
    //         cout<<OneMailBox[i][j]<<" ";
    //     cout<<endl;
    // }
    vector<vector<ll> >dp(n+1,vector<ll>(k+1,INT_MAX));
    for(int i=0;i<=k;i++)
        dp[0][i]=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=1;j<=k;j++)
        {
            for(ll k=0;k<=i;k++)
            {
                dp[i+1][j]=min(dp[i+1][j],dp[k][j-1]+OneMailBox[k][i]);
            }
        }
    }
    cout<<dp[n][k]<<endl;
}