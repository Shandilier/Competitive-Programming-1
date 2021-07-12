#include<bits/stdc++.h>
#define ll long long int
using namespace std;
// ll findDivisor(ll val)
// {

// }
int main()
{
    ll n;
    cin>>n;
    ll arr[n+1];
    queue<pair<ll,ll> >q;
    q.push({n,0});
    memset(arr,false,sizeof(arr));
    pair<ll,ll>p;
    ll height=0;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        ll val = p.first;
        ll count= p.second;
        height=max(height,count);
        for(ll i=2;i<=sqrt(val);i++)
        {
            if(val%i==0)
            {
                if(i!=val/i)
                {
                    q.push({i,count+1});
                    q.push({val/i,count+1});
                }
                else
                {
                    q.push({i,count+1});
                }
            }
        }
    }
    cout<<height<<endl;
    return 0;
}