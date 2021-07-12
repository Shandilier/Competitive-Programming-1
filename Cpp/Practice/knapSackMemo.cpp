#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll calc(ll **dp,ll w,ll wt[],ll val[],ll n)
{
    if(n==0 || w==0)
        return 0;
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(wt[n]>w)
    {
        dp[n][w]= calc(dp,w,wt,val,n-1);
        return dp[n][w];
    }
    else
    {
        dp[n][w]= max(val[n]+calc(dp,w-wt[n],wt,val,n-1),calc(dp,w,wt,val,n-1)); 
        return dp[n][w];
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
    ll **dp=new ll*[n];
    for(ll i=0;i<n;i++)
        dp[i]=new ll[w+1];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<w+1;j++)
            dp[i][j]=-1;
    }
    ll minm=INT_MAX;
    ll ans= calc(dp,w,wt,val,n-1);
    cout<<ans<<endl;
}