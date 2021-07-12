#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    ll arr[n*n+1];
    ll x,y;
    ll num_snakes,num_ladders;
    cin>>num_snakes>>num_ladders;
    map<ll,ll>snakes;
    map<ll,ll>ladders;
    for(ll i=0;i<num_ladders;i++)
    {
        cin>>x>>y;
        ladders[x]=y;
    }
    for(ll i=0;i<num_snakes;i++)
    {
        cin>>x>>y;
        snakes[y]=x;
    }
    ll i=0;
    ll count=10;
    while(i<n*n && count>=0)
    {
        cin>>x;
        if(i+x>n*n)
        {
            count--;
            continue;
        }
        i=i+x;
        if(snakes.find(i)!=snakes.end())
            i = snakes[i];
        else if(ladders.find(i)!=ladders.end())
            i = ladders[i];
        count--;
        if(i==n*n)
        {
            cout<<"YES"<<endl;
            return;
        }
        cout<<i<<" ";
    }
    cout<<"NO"<<endl;
}
int main()
{
    solve();
    return 0;
}