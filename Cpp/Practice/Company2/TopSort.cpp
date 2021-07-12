#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>adj[n];
    int edge;
    cin>>edge;
    int x,y;
    int indegree[n];
    memset(indegree,0,sizeof(indegree));
    for(int i=0;i<edge;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    queue<int>q;
    bool visited[n];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            visited[i]=true;
        }
    }

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<adj[x].size();i++)
        {
            if(!visited[adj[x][i]])
            {
                indegree[adj[x][i]]--;
                if(indegree[adj[x][i]]==0)
                {
                    q.push(adj[x][i]);
                    visited[adj[x][i]]=true;
                }
            }
        }
    }
}
