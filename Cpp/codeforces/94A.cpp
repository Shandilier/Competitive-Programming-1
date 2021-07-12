#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        string ans="";
        for(ll i=0;i<n;i++)
        {
            ans+=s[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}