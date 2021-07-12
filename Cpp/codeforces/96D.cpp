#include<bits/stdc++.h>
#define ll long long int
#define ii pair<int,int>
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll arr[n];
    for(ll i=0;i<n;i++)
        arr[i]=1;
    vector<ll>v;
    for(ll i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            arr[i]=arr[i-1];
            arr[i]++;
        }
        else
        {
            v.push_back(arr[i-1]);
        }
    }
    v.push_back(arr[n-1]);
    ll count=0;
    ll val=0;
    for(ll j=0;j<v.size();j++)   // 3 2 3
    {
        ll k=val;
        ll m = val+v[j];
        ll z = m;
        z--;
        
        for(;k<m;k++)
        {
            if(k>z)
                break;
            // cout<<k<<" "<<z<<endl;
            swap(arr[k],arr[z]);
            z--;

        }
        val+=v[j];
        
    }
    // for(ll i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    ll i=0,j=n-1;
    while(i<=j)
    {
        if(arr[i]>=2)
        {
            i = i + arr[i];
        }
        else
        {
            j--;
            i = i+ arr[i];
        }
        count++;
        // cout<<i<<" "<<j<<endl;
    }
    cout<<count<<endl;
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