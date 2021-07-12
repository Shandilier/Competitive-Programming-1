#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll solve()
{
    ll n;
    cin>>n;
    ll arr[n][n];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cin>>arr[i][j];
    }
    if(n==1)
        return arr[0][0];
    ll ans=0;
    ll val=0;
    ll j=n-1;
    ll count=n-1;
    while(1)
    {
        ll i=0;
        val=0;
        while(i<n && j<n && j>=0)
        {
            val+=arr[i][j];
            // cout<<i<<" "<<j<<endl;
            i++,j++;
            
        }
        if(j<0)
            break;
        count--;
        j=count;
        ans=max(ans,val);
    }
    ll i=1;
    count=1;
    while(1)
    {
        ll j=0;
        val=0;
        if(i==n-1 && j==0)
        {
            ans=max(ans,arr[n-1][0]);
            break;
        }
        while(i<n && j<n)
        {
            val+=arr[i][j];
            // cout<<i<<" "<<j<<" "<<arr[i][j]<<endl;
            i++,j++;
        }

        count++;
        i=count;
        ans=max(ans,val);
    }
    cout<<ans<<endl;
    return ans;
}
int main()
{
    ll t;
    cin>>t;
    ll m = 1;
    while(t--)
    {
        cout<<"Case #"<<m<<": "<<solve()<<endl;
        m++;
    }
    return 0;
}