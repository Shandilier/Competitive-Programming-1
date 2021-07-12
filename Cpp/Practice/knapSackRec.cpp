#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll calc(ll w,ll wt[],ll val[],ll n)
{
    if(n==0 || w==0)
        return 0;
    if(wt[n]>w)
        return calc(w,wt,val,n-1);
    else
    {
        return max(val[n]+calc(w-wt[n],wt,val,n-1),calc(w,wt,val,n-1));
    }
}
int main()
{
    ll n;
    cin>>n;
    ll val[n],wt[n];
    for(ll i=0;i<n;i++)
        cin>>val[i];
    for(ll i=0;i<n;i++)
        cin>>wt[i];
    ll w;
    cin>>w;
    // ll **dp=new ll[n];
    // for(ll i=0;i<n;i++)
    //     dp[i]=new ll[w+1];
    ll minm=INT_MAX;
    ll ans= calc(w,wt,val,n-1);
    cout<<ans<<endl;
}