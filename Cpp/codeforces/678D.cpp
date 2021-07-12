#include<bits/stdc++.h>
#define ll          long long int
#define loop(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n)    for(int (i)=0;(i)<n;(i)++)
#define bp          1000000007
#define sz(a)       int((a).size())
#define pb          push_back
#define mp          make_pair
#define all(c)      (c).begin(),(c).end()
#define F           first
#define S           second
using namespace std;
typedef pair<ll,ll> ii;
ll maxm=0;
void dfs(ll v,vector<ll>adj[],ll val[],ll leafCount[])
{
    if(adj[v].size()==0)
        leafCount[v]++;
    for(ll i=0;i<adj[v].size();i++)
    {
        dfs(adj[v][i],adj,val,leafCount);
        leafCount[v]+=leafCount[adj[v][i]];
        val[v]+=val[adj[v][i]];
    }
    if((val[v]+leafCount[v])%leafCount[v]==0)
        maxm=max(maxm,val[v]/leafCount[v]);
    else
        maxm=max(maxm,val[v]/leafCount[v]+1);
}
void solve()
{
    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    ll x;
    for(ll i=2;i<=n;i++)
    {
        cin>>x;
        adj[x].push_back(i);
    }
    ll val[n+1];
    for(ll i=1;i<=n;i++)
        cin>>val[i];
    ll leafCount[n+1];
    memset(leafCount,0,sizeof(leafCount));
    dfs(1,adj,val,leafCount);
    // for(ll i=1;i<=n;i++)
    //     cout<<val[i]<<" ";
    cout<<maxm<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll test;
    int test=1;
    // cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}


