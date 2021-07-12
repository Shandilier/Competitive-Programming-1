#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[100][100];
bool ans;
void calc(bool arr[],ll n,ll width,ll i)
{
    cout<<i<<endl;
    if(i<0 || i>n)
        return;
    if(!arr[i])
        return;
    if(i==n)
    {
        ans=true;
        return;
    }
    if(!ans)
    {
        calc(arr,n,width,i+i+1);
        calc(arr,n,width,i+i-1);
        calc(arr,n,width,2*i);
    }
}
int main()
{
    ll n;
    cin>>n;
    bool arr[1000];
    memset(arr,false,sizeof(arr));
    ll x;
    ans=false;
    arr[0]=true;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        arr[x]=true;
    }
    ll width;
    cin>>width;
    // memset(dp,false,sizeof(dp));
    // dp[0][0]=true;
    calc(arr,n,width,0);
    cout<<ans<<endl;
}