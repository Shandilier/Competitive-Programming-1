#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll findParent(ll parent[],ll x)
{
    if(parent[x]==x)
        return x;
    return findParent(parent,parent[x]);
}

int main()
{
    ll n;
    cin>>n;
    ll edge;
    cin>>edge;
    ll x,y;
    // vector<ll>adj[n];
    ll parent[n];
    for(ll i=0;i<n;i++)
        parent[i]=i;
    ll rank[n];
    memset(rank,0,sizeof(rank));
    for(ll i=0;i<edge;i++)
    {
        cin>>x>>y;
        a = findParent(parent,x);
        b = findParent(parent,y);
        if(a==b)
        {
            cout<<"Cycle found"<<endl;
            break;
        }
    }
    return 0;
}