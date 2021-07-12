#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll n = s.length();
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    if(n==0 || s[0]=='0')
    {
        cout<<0<<endl;
        return 0;
    }
    dp[0]=1;
    for(ll i=1;i<=n;i++)
    {
        if(s[i-1]>'0')
            dp[i]=dp[i-1];
        if(i>=2)
        {
            if(s[i-2]=='2' && s[i-1]<'7')
                dp[i]+=dp[i-2];
            else if(s[i-2]=='1')
                dp[i]+=dp[i-2];
        }
    }
    cout<<dp[n]<<endl;
}