#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int> >adj[v];
    int x,y,weight;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y>>weight;
        adj[x].push_back(make_pair(y,weight));
        adj[y].push_back(make_pair(x,weight));
    }
    set<pair<int,int> >s;
    s.insert(make_pair(0,0));  // first is weight and second is vertex
    pair<int,int>p;
    vector<int>dist(v,INT_MAX);
    dist[0]=0;
    // cout<<"Hey"<<endl;
    while(!s.empty())
    {
        p = *(s.begin());
        s.erase(s.begin());
        int v = p.second;
        
        for(int i=0;i<adj[v].size();i++)
        {
            // cout<<"hey"<<endl;
            int u =adj[v][i].first;
            int weight = adj[v][i].second;
            if(dist[u]>dist[v]+weight)
            {
                if(dist[u]!=INT_MAX)
                    s.erase(s.find(make_pair(dist[u],u)));  
                dist[u]=dist[v]+weight;
                s.insert(make_pair(dist[u],u));
            }
        }
        // cout<<"Hello"<<endl;
    }
    for(int i=0;i<v;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}

