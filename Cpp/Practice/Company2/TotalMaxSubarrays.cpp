#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll target;
    cin>>target;
    ll count=0;
    ll ans=0;
    ll flag=2;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]<target)
        {
            count++;
        }
        else if(arr[i]>target)
        {
            ans+=((count)*(count-1))/2;
            count=0;
            flag=1;
        }
        else
        {
            count++;
            flag=0;
        }
    }
    if(flag==0)
    {
        ans+=((count)*(count-1))/2;
    }
    cout<<ans<<endl;
    return 0;
}