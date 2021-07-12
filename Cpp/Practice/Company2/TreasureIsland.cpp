#include<bits/stdc++.h>
#define ll long long int
#define ii pair<int,int>
using namespace std;
ll arr1[4]={0,1,0,-1};
ll arr2[4] = {1,0,-1,0};
char arr[100][100];
bool isSafe(ll xnew,ll ynew,ll n)
{
    if(xnew>=0 && xnew<n && ynew>=0 && ynew<n && arr[xnew][ynew]!='D')
        return true;
    return false;
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cin>>arr[i][j];
    }
    ll count=0;
    queue<pair<pair<ll,ll>,ll> >q;
    if(arr[0][0]=='X')
    {
        cout<<0<<endl;
        return 0;
    }
    q.push({{0,0},0});
    pair<pair<ll,ll>,ll>p;
    ll xnew,ynew;
    bool visited[n][n];
    memset(visited,false,sizeof(visited));
    visited[0][0]=true;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        ll x = p.first.first;
        ll y = p.first.second;
        // visited[x][y]=true;
        ll dist = p.second;
        if(arr[x][y]=='X')
        {
            cout<<dist<<endl;
            break;
        }
        for(ll i=0;i<4;i++)
        {
            xnew = x+arr1[i];
            ynew = y+arr2[i];
            if(isSafe(xnew,ynew,n) && !visited[xnew][ynew])
            {
                q.push({{xnew,ynew},dist+1});
                visited[xnew][ynew]=true;
            }
        }
    }
    return 0;
}