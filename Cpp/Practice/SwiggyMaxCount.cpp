#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[101][101][101];
ll cost(vector<vector<ll> >v,ll row1,ll row2,ll col1, ll col2)
{
    ll ans=0;
    if(row1==row2 && col1==col2)
    {
        if(v[row1][col1]==1)
            return 1;
        return 0;
    }
    
    if(v[row1][col1]==1)
        ans++;
    if(v[row2][col2]==1)
        ans++;
    return ans;
}
ll solve(vector<vector<ll> >v, ll row1,ll col1,ll row2,ll &ans,ll n,ll m)
{
    int col2 = (row1+row2)-col2;
    if(row1==n-1 && row2==n-1 && col1==m-1 && col2 ==m-1)
        return 0;
    if(row1>=n || row2>=n || col1>=m || col2>=m)
        return INT_MIN;
    if(dp[row1][col1][row2]!=-1)
        return dp[row1][col1][col2];
    ll val = INT_MIN;
    if(v[row1][col1+1]!=-1 && v[row2][col2+1])
        val = max(val,cost()+solve(v,row1,col1+1,row2,ans,n,m));
    if(v[row1+1][col1]!=-1 && v[row2+1][col2]!=-1)
        val = max(val,cost()+solve(v,row1+1,col1,row2+1,ans,n,m));
    if(v[row1+1][col1]!=-1 && v[row2][col2+1]!=-1)
        val = max(val,cost()+solve(v,row1+1,col1,row2,ans,n,m));
    if(v[row1][col1+1]!=-1 && v[row2+1][col2]!=-1)
        val = max(val,cost()+solve(v,row1,col1+1,row2+1,ans,n,m));
    return val;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> >v(n,vector<ll>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    ll ans=-1;
    if(v[0][0]==-1 || v[n-1][m-1]==-1)
    {
        cout<<ans<<endl;
        return 0;
    }
    if(v[0][0]==1)
    {
        ans++;
        v[0][0]=0;
    }
    if(v[n-1][m-1]==1)
    {
        ans++;
        v[n-1][m-1]=0;
    }
    ans+ = solve(v,0,0,0,ans,n,m);
    cout<<ans<<endl;   
}