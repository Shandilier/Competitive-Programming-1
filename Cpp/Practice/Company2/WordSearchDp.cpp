#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool isPresent(vector<string>v,string s)
{
    for(ll i=0;i<v.size();i++)
    {
        if(v[i]==s)
        {
            // cout<<v[i]<<endl;
            return true;
        }
    }
    return false;
}
int main()
{
    vector<string>v;
    ll n;
    cin>>n;
    string s1;
    for(ll i=0;i<n;i++)
    {
        cin>>s1;
        v.push_back(s1);
    }
    string s;
    cin>>s;
    ll m =s.length();
    bool dp[m+1];
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=m;i++)
    {
        if(dp[i]==false);
        {
            if(isPresent(v,s.substr(0,i)))
                dp[i]=true;
        }
        if(dp[i]==true)
        {
            if(i==m)
            {
                cout<<"true"<<endl;
                return 0;
            }
            for(ll j=i+1;j<=m;j++)
            {
                // cout<<s.substr(i,j-i)<<endl;
                if(dp[j]==false);
                {
                    if(isPresent(v,s.substr(i,j-i)))
                    {
                        // cout<<j<<endl;
                        dp[j]=true;
                    }
                }
                if(j==m && dp[j]==true)
                {
                    // cout<<i<<endl;
                    cout<<"true"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"false"<<endl;
    return 0;
}