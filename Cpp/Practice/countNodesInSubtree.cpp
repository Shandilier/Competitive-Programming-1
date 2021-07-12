#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dfs(ll *count,ll i,vector<ll>adj[])
{
    // cout<<i<<" ";
    ll val=1;
    for(ll j=0;j<adj[i].size();j++)
    {
        val+=dfs(count,adj[i][j],adj);
    }
    count[i]=val;
    return count[i];
}
void solve()
{
    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    ll x,y;
    ll edge;
    cin>>edge;
    for(ll i=0;i<edge;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    ll count[n+1]={0};
    ll res = dfs(count,1,adj);
    for(ll i=1;i<=n;i++)
    {
        cout<<count[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    solve();
    return 0;
}