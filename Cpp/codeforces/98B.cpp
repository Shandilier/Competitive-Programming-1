#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    ll val = ceil(sum/double(n-1));
    ll maxm=*max_element(arr,arr+n);
    ll gmax = max(val,maxm);
    // cout<<gmax<<" "<<val<<endl;
    ll ans = gmax*(n-1)-sum;
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
