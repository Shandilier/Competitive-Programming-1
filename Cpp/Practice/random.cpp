#include<bits/stdc++.h>
using namespace std;
bool isCyclic(int u,bool visited[],int parent,vector<int>&res,vector<int>adj[])
{
    visited[u]=true;
    res.push_back(u);
    for(int i=0;i<adj[u].size();i++)
    {
        if(!visited[adj[u][i]])
        {
            if(isCyclic(adj[u][i],visited,u,res,adj))
                return true;
        }
        else if(adj[u][i]!=u)
            return true;
    }
    res.pop_back();
    return false;
}
void dfs(int u,vector<int>adj[],int count,vector<int>&ans)
{
    ans[u]=count;
    for(int i=0;i<adj[u].size();i++)
    {
        if(res[adj[u][i]]!=0)
        {
            dfs(adj[u][i],adj,count+1,ans);
        }
    }
}
vector<int> nodeDistance(int g_nodes,vector<int>g_from,vector<int>g_to)
{
    vector<int>adj[g_nodes];
    for(int i=0;i<g_from.size();i++)
    {
        adj[g_from[i]].push_back(g_to[i]);
        adj[g_to[i]].push_back(g_from[i]);
    }
    int parent[g_nodes];
    memset(parent,-1,sizeof(parent));
    int visited[g_nodes];
    memset(visited,false,sizeof(visited));
    vector<int>res;
    for(int i=0;i<g_nodes;i++)
    {
        if(!visited[i])
        {
            if(isCyclic(i,visited,-1,res,adj))
                break;
        }
    }
    vector<int>ans(g_nodes,-1);
    for(int i=0;i<res.size();i++)
        ans[res[i]]=0;
    
    int count;
    for(int i=0;i<res.size();i++)
    {
        count=0;
        dfs(res[i],adj,count,ans);
    }
    return ans;
}


int getMinimumSeconds(vector<int>height, int h,int u,int v)
{
    int n=height.size();
    if(n==0)
        return 0;
    int ans=0;
    int i=0;j=n-1;
    while(i<j)
    {
        if(height[i]+height[j]<h)
        {
            if(2*u>=v)
            {
                ans+=v;
                i++;
                j--;
            }
            else
            {
                ans+=u;
                j--;
            }
        }
        else
        {
            ans+=u;
            j--;
        }
    }
    if(i==j)
    {
        ans+=u;
    }
    return ans;
}