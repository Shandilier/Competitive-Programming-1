#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool dfs(vector<bool>&visited,vector<bool>&recStack,ll n,vector<ll>adj[],ll i,ll parent)
{
    if(i>=n)
        return false;
    visited[i]=true;
    recStack[i]=true;
    for(ll j=0;j<adj[i].size();j++)
    {
        if(!visited[adj[i][j]])
        {
            if(dfs(visited,recStack,n,adj,adj[i][j],i))
                return true;
        }
        else if(recStack[adj[i][j]])
            return true;
    }
    recStack[i]=false;
    return false;
}
int main()
{
    ll n;
    cin>>n;
    ll edge;
    cin>>edge;
    vector<ll>adj[n];
    ll x,y;
    for(ll i=0;i<edge;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    vector<bool>visited(n,false);
    vector<bool>recStack(n,false);
    for(ll i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(dfs(visited,recStack,n,adj,i,-1))
            {
                cout<<"true"<<endl;
                return 0;
            }
        }
    }
    cout<<"false"<<endl;
}