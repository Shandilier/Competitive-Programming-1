#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll n=s.length();
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    for(ll k=2;k<=n;k++)
    {
        for(ll i=0;i<n-k+1;i++)
        {
            ll j=i+k-1;
            if(s[i]==s[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else
            { 
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}
