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
    ll val=1;
    ll maxm=1,gmax=1,minm=1;
    ll flag=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            maxm = maxm*arr[i];
            minm = min(val,minm*arr[i]);
            flag=1;
        }
        else if(arr[i]==0)
        {
            maxm=1;
            minm=1;
        }
        else
        {
            ll temp = maxm;
            maxm = max(minm*arr[i],val);
            minm = temp*arr[i];
        }
        gmax = max(gmax,maxm);
    }
    if(flag==0)
        cout<<0<<endl;
    else
    {
        cout<<gmax<<endl;
    }
    
}
