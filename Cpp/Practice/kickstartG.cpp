#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll solve()
{
    string s;
    cin>>s;
    ll n=s.length();
    ll count=0;
    if(s.length()<9)
    {
        return count;
    }
    vector<ll>v1,v2;

    for(ll i=0;i<n-3;i++)
    {
        if(s[i]=='K' && s[i+1]=='I' && s[i+2]=='C' && s[i+3]=='K')
        {
            v1.push_back(i+3);
        }
    }
    for(ll i=0;i<n-4;i++)
    {
        if(s[i]=='S' && s[i+1]=='T' && s[i+2]=='A' && s[i+3]=='R' && s[i+4]=='T')
        {
            v2.push_back(i);
        }
    }
    ll i=0,j=0;
    // for(ll i=0;i<v1.size();i++)
    // {
    //     cout<<v1[i]<<" ";
    // }
    // cout<<endl;
    // for(ll i=0;i<v2.size();i++)
    // {
    //     cout<<v2[i]<<" ";
    // }
    // cout<<endl;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]<v2[j])
        {
            count+=(v2.size()-j);
            i++;
        }
        else
        {
            j++;
        }
    }
    return count;
}
int main()
{
    ll t;
    cin>>t;
    ll m = 1;
    while(t--)
    {
        cout<<"Case #"<<m<<": "<<solve()<<endl;
        m++;
    }
    return 0;
}