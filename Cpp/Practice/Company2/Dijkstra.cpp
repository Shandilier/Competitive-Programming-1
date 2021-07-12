#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll edge;
    cin>>edge;
    vector<pair<ll,ll> >adj[n];
    ll x,y,weight;
    for(ll i=0;i<edge;i++)
    {
        cin>>x>>y>>weight;
        adj[x].push_back({y,weight});
        adj[y].push_back({x,weight});
    }
    set<pair<ll,ll> >s;
    pair<ll,ll>p;
    ll dist[n];
    for(ll i=0;i<n;i++)
        dist[i]=INT_MAX;
    dist[0]=0;
    s.insert({0,0});
    while(!s.empty())
    {
        p = *(s.begin());
        ll weight = p.first;
        ll u = p.second;
        for(ll i=0;i<adj[u].size();i++)
        {
            ll v = adj[u][i];
            if(dist[u]+weight <dist[v])
            {
                if(dist[v]!=INT_MAX)
                    s.erase(s.find({dist[v],v}));
                dist[v]=dist[u]+weight;
                s.insert({dist[v],v});
            }
        }
    }
}