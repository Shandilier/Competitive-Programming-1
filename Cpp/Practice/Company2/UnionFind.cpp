#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll findParent(ll x,ll parent[])
{
    if(parent[x]==x)
        return parent[x];
    return findParent(parent[x],parent);
}
void Union(ll x,ll y,ll parent[],ll rank[])
{
    if(rank[x]>rank[y])
    {
        parent[y]=x;
    }
    else if(rank[y]>rank[x])
    {
        parent[x]=y;
    }
    else
    {
        parent[x]=y;
        rank[y]++;
    }
}
bool isCyclic()
{
    ll v;
    cin>>v;
    ll edges;
    cin>>edges;
    vector<ll>adj[v];
    ll x,y;
    ll parent[v];
    for(ll i=0;i<v;i++)
        parent[i]=i;
    ll rank[v];
    memset(rank,0,sizeof(rank));
    // cout<<edges<<endl;
    for(ll i=0;i<edges;i++)
    {
        cin>>x>>y;
        ll parent1 = findParent(x,parent);
        ll parent2 = findParent(y,parent);
        // cout<<parent1<<" "<<parent2<<endl;
        if(parent1==parent2)
            return true;
        Union(x,y,parent,rank);
        // cout<<parent[x]<<" "<<parent[y]<<endl;
    }
    return false;
}
int main()
{
    if(isCyclic())
        cout<<"Cycle Detected"<<endl;
    else
        cout<<"No cycle found"<<endl;
        return 0;
}