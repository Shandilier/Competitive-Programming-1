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
    ll minm=1,maxm=1;
    ll gmax=1;
    ll flag=0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            maxm=maxm*arr[i];
            flag=1;
            minm = min(minm*arr[i],1);
        }
        else if(arr[i]==0)
        {
            maxm=1;
            minm=1;
        }
        else
        {
            ll temp = maxm;
            maxm = max(minm*arr[i],1);
            minm=temp*arr[i]
        }
        gmax=max(gmax,maxm);
    }
    if(flag==1)
    {
        cout<<gmax<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    
}