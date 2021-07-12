#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    ll arr[n][n];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cin>>arr[i][j];
    }
    vector<pair<ll,ll> >v;
    if(arr[0][1]==arr[1][0])
    {
        if(arr[1][0]==0)
        {
            if(arr[n-1][n-2]==0)
            {
                v.push_back({n,n-1});
            }
            else if(arr[n-2][n-1]==0)
                v.push_back({n-1,n});
            else
            {
                cout<<0<<endl;
                return;
            }
            
        }
        else if(arr[1][0]==1)
        {
            if(arr[n-1][n-2]==1)
            {
                v.push_back({n,n-1});
            }
            else if(arr[n-2][n-1]==1)
                v.push_back({n-1,n});
            else
            {
                cout<<0<<endl;
                return;
            }
        }
    }
    else
    {
        for(ll i=0;i<n-1;i++)
        {
            for(ll j=0;j<n-1;j++)
            {
                if((i!=0 && j!=0))
                {
                    if(arr[i][j]==arr[i+1][j] && arr[i][j]==arr[i][j+1])
                        v.push_back({i+1,j+1})
                }
                if(v.size()==2)
                    break;
            }
            if(v.size()==2)
                break;
        }
        if(arr[n-1][0]==arr[n-1][1])
            v.push_back({n,1});
        if(arr[0][n-1]==arr[1][n-1])
            v.push_back({1,n});
    }
    cout<<v.size()<<endl;
    if(v.size()==0)
        return;
    for(ll i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
