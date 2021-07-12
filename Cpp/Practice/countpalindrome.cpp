#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s;
    cin>>n;
    ll count=0;
    ll n = s.length();
    ll dp[n][n];
    memset(dp,0,sizeof(n))
    for(ll i=0;i<n;i++)
    {
        dp[i][i]=1;
        count++;
    }
    for(ll i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=1;
            count++;
        }
        else
        {
            dp[i][i+1]=0;
        }
        
    }
    ll j;
    for(ll k=3;k<=n;k++)
    {
        for(ll i=0;i<n-k+1;i++)
        {
            j=i+k-1;
            if(s[i]==s[j])
        }
    }

    return 0;
}