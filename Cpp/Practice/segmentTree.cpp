#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[100000],seg[4*100000];
void createSegmentTree(ll index, ll low,ll high)
{
    if(low == high)
    {
        seg[index]=arr[low];
        return;
    }
    ll mid = (low+high)/2;
    createSegmentTree(2*index+1,low,mid);
    createSegmentTree(2*index+2,mid+1,high);
    seg[index] = max(seg[2*index+1],seg[2*index+2]);
}
ll findMax(ll index,ll low,ll high,ll l,ll r)
{
    if(low>=l && high<=r)
    {
        return seg[index];
    }
    if(low>r || high<l)
        return INT_MIN;
    ll mid = (low+high)/2;

    return max(findMax(2*index+1,low,mid,l,r),findMax(2*index+2,mid+1,high,l,r));
}

int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    createSegmentTree(0,0,n-1);
    ll q;
    cin>>q;
    ll x,y;
    while(q--)
    {
        cin>>x>>y;
        ll ans = findMax(0,0,n-1,x,y);
        cout<<ans<<endl;
    }
}