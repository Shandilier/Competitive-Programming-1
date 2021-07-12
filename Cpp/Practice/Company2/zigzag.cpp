#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll n;
    cin>>n;
    ll m=s.length();
    vector<vector<char> >v(n,vector<char>(m,'0'));
    ll i=0,j=0,flag=0;
    ll count=0;
    if(n==1)
    {
        cout<<s<<endl;
        return 0;
    }
    while(j<m)
    {
        // cout<<i<<" "<<j<<" "<<s[j]<<endl;
        if(i==n-1)
        {
            flag=1;
        }
        else if(i==0)
        {
            flag=0;
        }
        if(flag==0)
        {
            v[i][j]=s[j];
            i++;
        }
        else
        {
            v[i][j]=s[j];
            i--;
        }
        j++;
    }
    string ans="";
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(v[i][j]!='0')
                ans+=v[i][j];
        }
    }
    cout<<ans<<endl;
}