#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct parameters
{
    ll index;
    ll minJump;
    string seq; 
};
void findMinJumps(ll dp[],ll arr[],ll n)
{
    dp[n-1]=0;
    ll minm;
    for(ll i=n-2;i>=0;i--)
    {
        minm=INT_MAX;
        for(ll j=1;j<=arr[i];j++)
        {
            if(i+j<n && dp[i+j]!=INT_MAX)
            {
                if(dp[i+j]<minm)
                    minm=dp[i+j];
            }
        }
        dp[i]=minm+1;
    }  
    for(ll i=0;i<n;i++)
        cout<<dp[i]<<" ";
    cout<<endl; 
}
void findAllPaths(ll dp[],ll arr[],ll n)
{
    queue<parameters>q;
    q.push({0,dp[0],"0"});
    while(q.size()>0)
    {
        parameters p = q.front();
        q.pop();
        ll len = p.minJump;
        ll idx = p.index;
        string s = p.seq;
        if(len == 0)
        {
            cout<<s<<endl;
            continue;
        }
        for(ll i=1;i<=arr[idx];i++)
        {
            if(idx+i<n && dp[idx+i]==len-1)
            {
                string s1 = s+"  "+to_string(idx+i);
                q.push({idx+i,len-1,s1});
            }
            
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll dp[n];
    for(ll i=0;i<n;i++)
        dp[i]=INT_MAX;
    findMinJumps(dp,arr,n);
    findAllPaths(dp,arr,n);
    return 0;
}