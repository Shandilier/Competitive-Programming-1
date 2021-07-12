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

bool compare(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}
void solve()
{
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    rep(i,n)
        cin>>arr[i];
    map<ll,ll>m;
    ll count[32];
    memset(count,0,sizeof(count));
    for(ll i=0;i<n;i++)
    {
        ll j=0;
        while(arr[i])
        {
            count[j]+=(arr[i]%2);
            arr[i]/=2;
            j++;
        }
    }
    vector<ii>v(32);
    for(ll i=0;i<32;i++)
    {
        v[i].F=(1<<i)*count[i];
        v[i].S=i;
    }
    // for(ll i=0;i<3;i++)
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    sort(v.begin(),v.end(),compare);
    ll ans=0;
    ll i=0;
    for(;i<k;i++)
    {
        ans |=(1<<v[i].second);
    }
    cout<<ans<<endl;
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