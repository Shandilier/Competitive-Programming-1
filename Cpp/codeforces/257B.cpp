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
typedef pair<long long int,long long int> ii;
void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ii>adj[n+1];
    ll x,y,z;
    rep(i,m)
    {
        cin>>x>>y>>z;
        adj[x].pb(mp(y,z));
        adj[y].pb(mp(x,z));
    }
    vector<ii>v(k+1);
    rep(i,k)
    {
        cin>>x>>y;
        v[i].F=x;
        v[i].S=y;
    }
    ll dist[n+1];
    rep(i,n+1)
    {
        dist[i]=INT_MAX;
    }
    dist[1]=0;
    priority_queue<ii,vector<ii>,greater<ii> >pq;
    pair<ll,ll>p;
    pq.push(mp(0,1));
    vector<ii> :: iterator it;
    while(!pq.empty())
    {
        p=pq.top();
        pq.pop();
        ll u = p.S;
        
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            ll v = it->first;
            ll weight = it->second;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
                pq.push(mp(dist[v],v));
            }
        }
    }
    ll count=0;
    ll flag[n+1]={0};
    rep(i,k)
    {
        if(dist[v[i].F]<=v[i].S)
            count++;
        else
        {

            if(flag[v[i].F]==0)
            {
                dist[v[i].F]=v[i].S;
                flag[v[i].F]=1;
            }
            else
            {
                dist[v[i].F]=v[i].S;
                count++;
            }      
        }   
    }
    cout<<count<<endl;
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

