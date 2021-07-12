#include<bits/stdc++.h>
#define ll long long int
#define ii pair<int,int>
using namespace std;
ll parent[100001];
ll rankVal[100001];
ll findParent(ll x)
{
    if(parent[x]==x)
        return parent[x];
    return findParent(parent[x]);
}
void Union(ll x,ll y)
{
    ll parent1 = findParent(x);
    ll parent2 = findParent(y);
    if(rankVal[parent1]>rankVal[parent2])
        parent[parent2]=parent1;
    else if(rankVal[parent1]<rankVal[parent2])
        parent[parent1]=parent2;
    else
    {
        // cout<<parent1<<" "<<parent2<<endl;
        parent[parent1]=parent2;
        rankVal[parent2]++;
    }
}
int main()
{
    ll n;
    cin>>n;
    ll e;
    cin>>e;
    vector<ii>edges;
    ll x,y,z;
    for(ll i=0;i<e;i++)
    {
        cin>>x>>y;
        edges.push_back({x,y});
    }
    for(ll i=0;i<=n;i++)
        parent[i]=i;
    memset(rankVal,0,sizeof(rankVal));
    ll count=n;
    for(ll i=0;i<edges.size();i++)
    {
        // cout<<edges[i].first<<" "<<edges[i].second<<endl;
        ll parent1 = findParent(edges[i].first);
        ll parent2 = findParent(edges[i].second);
        // cout<<parent1<<" "<<parent2<<endl;
        if(parent1!=parent2)
        {
            
            Union(edges[i].first,edges[i].second);
            count--;
        }
    }
    // for(ll i=0;i<=n;i++)
    //     cout<<parent[i]<<" ";
    cout<<endl;
    ll m;
    cin>>m;
    vector<pair<ll,ii> >newEdges;

    for(ll i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        newEdges.push_back(make_pair(z,make_pair(x,y)));
    }
    ll totalCost = 0 ;
    sort(newEdges.begin(),newEdges.end());
    cout<<parent[6]<<endl;
    for(ll i=0;i<newEdges.size();i++)
    {
        cout<<parent[6]<<endl;
        cout<<newEdges[i].second.first<<" "<<newEdges[i].second.second<<" "<<parent[newEdges[i].second.first]<<" "<<parent[newEdges[i].second.second]<<endl;
        if(count==1)
            break;
        ll parent1 = findParent(newEdges[i].second.first);
        ll parent2 = findParent(newEdges[i].second.second);
        cout<<parent1<<" "<<parent2<<endl;
        
        if(parent1!=parent2)
        {
            Union(newEdges[i].second.first,newEdges[i].second.second);
            totalCost+=newEdges[i].first;
            count--;
        }
    }
    cout<<totalCost<<endl;
    return 0;
}