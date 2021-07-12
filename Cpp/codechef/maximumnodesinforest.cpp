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

void dfs(ll val, ll ans, vector<ll>adj[],ll count[])
{
    for(ll i=0;i<adj[val].size();i++)
    {
        count[ans]++;
        dfs(adj[val][i],ans+1,adj,count);
    }
}
ll calc(vector<vector<ll> >adj[],ll val, ll a,ll b,ll &flag1,ll &flag2)
{
    if(adj[val].size()==0)
        return -1;
    if(flag1==1 && flag2==1)
        return val;
    if()
    for(ll i=0;i<adj[val].size();i++)
    {
        calc(adj,adj[val][i],a,b);
    }
}
void solve()
{
    ll n;
    cin>>n;
    ll parent[n];
    vector<ll>root;
    vector<ll>adj[n];
    rep(i,n)
    {
        cin>>parent[i];
        if(parent[i]==-1)
            root.push_back(i);
        else
        {
            adj[parent[i]].pb(i);
        }
    }
    ll count[n];
    memset(count,0,sizeof(count));
    ll ans=0,maxm=INT_MIN;
    // for(ll i=0;i<root.size();i++)
    // {
    //     dfs(root[i],ans,adj,count);
    // }
    ll a,b;
    cin>>a>>b;
    ll flag1=0,flag2=0;
    for(ll i=0;i<root.size();i++)
    {
        ll ans = calc(adj,root[i],a,b,flag1,`);
        if(ans==-1)
            continue;
        else
        {
            break;
        }
        
    }
    // cout<<*max_element(count,count+n)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll test;
    // int test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}