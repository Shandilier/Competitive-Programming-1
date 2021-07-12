#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll sum;
    cin>>sum;
    unordered_map<ll,ll>m;
    ll val=0;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        val+=arr[i];
        if(arr[i]==sum)
            ans++;
        if(m.find(val-sum)!=m.end())
        {
            ans+=m[val-sum];
        }
        m[val]++;
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
