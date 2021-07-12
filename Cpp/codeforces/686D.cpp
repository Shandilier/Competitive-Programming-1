#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    ll x=n;
    map<ll,ll>m;
    while(n%2==0)
    {
        if(m.find(2)==m.end())
            m[2]=1;
        else
        {
            m[2]++;
        }
        n/=2;       
    }
    for(ll i=3;i<=sqrt(n);i+=2)
    {
        ll count=0;
        while(n%i==0)
        {
            if(count==0)
            {
                m[i]=1;
                count++;
            }
            else
            {
                m[i]++;
            }
            n/=i;
        }
    }
    if(n>2)
    {
        if(m.find(n)==m.end())
            m[n]=1;
        else
        {
            m[n]++;
        }
    }
    map<ll,ll> ::iterator it;
    ll maxm=0;
    ll ans;
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second > maxm)
        {
            maxm=it->second;
            ans=it->first;
        }
    }
    maxm--;
    ll val=maxm;
    while(maxm>0)
    {
        x/=ans;
        maxm--;
    }
    cout<<val+1<<endl;
    for(ll i=0;i<val;i++)
    {
        cout<<ans<<" ";
    }
    cout<<x<<endl;
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