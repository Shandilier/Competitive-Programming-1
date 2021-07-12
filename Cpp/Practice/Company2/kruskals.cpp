#include<bits/stdc++.h>
#define ll long long int
#define ii pair<int,int>
using namespace std;
ll findParent(ll x, ll parent[])
{
    if(parent[x]==x)
        return parent[x];
    return findParent(parent[x],parent);
}
void Union(ll x,ll y,ll parent[],ll rank[])
{
    ll parent1 = findParent(x,parent);
    ll parent2 = findParent(y,parent);
    if(rank[parent1]>rank[parent2])
    {
        parent[parent2]=parent1;
    }
    else if(rank[parent2]>rank[parent1])
    {
        parent[parent1]=parent2;
    }
    else
    {
        parent[parent1]=parent2;
        rank[parent2]++;
    }
}
int main()
{
    ll v;
    cin>>v;
    ll edge;
    cin>>edge;
    vector<pair<ll,ii> >adj;
    ll x,y,weight;
    for(ll i=0;i<edge;i++)
    {
        cin>>weight>>x>>y;
        adj.push_back({weight,{x,y}});
    }
    ll parent[v+1];
    ll rank[v+1];
    memset(rank,0,sizeof(rank));
    for(ll i=0;i<=v;i++)
        parent[i]=i;
    ll count=0;
    // for(ll i=0;i<edge;i++)
    //     cout<<adj[i].first<<" "<<adj[i].second.first<<" "<<adj[i].second.second<<endl;
    sort(adj.begin(),adj.end());
    ll i=0;
    while(count!=v-1 && i<edge)
    {
        weight = adj[i].first;
        x = adj[i].second.first;
        y = adj[i].second.second;
        ll parent1 = findParent(x,parent);
        ll parent2 = findParent(y,parent);
        if(parent1==parent2)
        {
            // cout<<i<<endl;
            i++;
            continue;
        }
        else
        {
            // cout<<x<<" "<<y<<" "<<weight<<endl;
            Union(x,y,parent,rank);
            
            i++;
        }
        count++;
    }    
    for(ll i=0;i<=v;i++)
        cout<<parent[i]<<" ";
    cout<<endl;
}   