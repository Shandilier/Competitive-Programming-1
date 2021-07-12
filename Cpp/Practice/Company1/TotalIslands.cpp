#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr1[8]={0,1,0,-1,-1,1,-1,1};
ll arr2[8]={1,0,-1,0,-1,1,1,-1};
char arr[100][100];
bool isSafe(char arr[][100],ll x,ll y,ll n,ll m)
{
    if(x<n && y<m && x>=0 && y>=0 && arr[x][y]=='#')
        return true;
    return false;
}
void dfs(char arr[][100],ll i,ll j,ll n,ll m)
{
    // cout<<i<<" "<<j<<endl;
    arr[i][j]='.';
    for(ll k=0;k<8;k++)
    {
        if(isSafe(arr,i+arr1[k],j+arr2[k],n,m))
        {
            dfs(arr,i+arr1[k],j+arr2[k],n,m);
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    memset(arr,'#',sizeof(arr));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
    }
    ll count=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(arr[i][j]=='#')
            {
                dfs(arr,i,j,n,m);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}