#include<bits/stdc++.h>
#define ll long long int
#define rep(i,n)  for(int i=0;i<n;i++)
#define ii pair<int,int> 
#define pb push_back 
using namespace std;

void formAdjacencyList(vector<ll>adj[],ll x,ll y)
{
    adj[x].pb(y);
}
ll countChildren(ll n,vector<ll>adj[],vector<ll> &count,ll i)
{
    cout<<i<<" "<<adj[i].size()<<endl;
    for(ll j=0;j<adj[i].size();j++)
    {
        count[i]+=countChildren(n,adj,count,adj[i][j]);
    }
    return count[i]+1;
}
void solve()
{
    ll n,e;
    cin>>n>>e;
    vector<ll>adj[n];
    ll x,y;
    rep(i,e)
    {
        cin>>x>>y;
        formAdjacencyList(adj,x,y);
    }
    vector<ll>count(n,0);
    cout<<"hello"<<endl;
    ll val = countChildren(n,adj,count,0);
    cout<<"world"<<endl;
    for(ll i=0;i<n;i++)
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
