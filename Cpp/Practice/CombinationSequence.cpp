#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve(ll n,ll k)
{
    ll fact[n+1];
    fact[0]=1;
    for(ll i=1;i<=n;i++)
    {
        fact[i]=fact[i-1]*i;
    }
    vector<ll>v;
    for(ll i=0;i<n;i++)
        v.push_back(i+1);
    ll sum=0;
    string s="";
    for(ll i=0;i<n;i++)
    {
        ll index = k/fact[n-i-1];
        if(k%fact[n-i-1]==0)
            index--;
        char c = v[index]+'0';
        s+=c;
        v.erase(v.begin()+index);
        k-=(fact[n-i-1]*index);
    }
    cout<<s<<endl;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    solve(n,k);
}
