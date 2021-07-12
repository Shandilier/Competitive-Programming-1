#include<bits/stdc++.h>
#define ll long long int
#define ii pair<int,int>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    ll n = s.length();
    bool dp[n][n];
    memset(dp,false,sizeof(dp));
    ll ans=0;
    unordered_map<string,ll>m;
    for(ll i=0;i<n;i++)
    {
        string s1 = "";
        s1+=s[i];
        if(m.find(s1)==m.end())
        {
            m[s1]=1;
            ans++;
            dp[i][i]=true;
        }
        else
        {
            dp[i][i]=true;
        }
        
    }
    for(ll i=0;i<n-1;i++)
    {
        string s2 = s.substr(i,2);
        if(s[i]==s[i+1] && m.find(s2)==m.end())
        {
            
            m[s2]=1;
            ans++;
        }
        else if(s[i]==s[i+1] && m.find(s2)!=m.end())
        {
            dp[i][i]=true;
        }
    }
    for(ll k=3;k<=n;k++)
    {
        for(ll i=0;i<n-k+1;i++)
        {
            ll j = i+k-1;
            string s1=s.substr(i,i+k);
            if(s[i]==s[j] && dp[i+1][j-1] && m.find(s1)==m.end())
            {
                // cout<<s1<<endl;
                dp[i][j]=true;
                m[s1]=1;
                ans++;
            }
            else if(s[i]==s[i+1] && dp[i+1][j-1] && m.find(s1)!=m.end())
            {
                dp[i][i]=true;  
            }
        }
    }
    cout<<ans<<endl;
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
