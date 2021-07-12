#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll x,y;
    cin>>x>>y;
    ll minm=min(x,y);
    ll ans=minm*2;
    if(ans==x+y)
    {
        cout<<ans<<endl;
        return;
    }
    ll maxm=max(x,y);
    ll diff = maxm-minm;
    ans+=diff*2-1;
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