#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll segment[10000];

void buildSegmentTree(ll arr[],ll low,ll high,ll index)
{
    if(low==high)
    {
        segment[index]=arr[low];
        return;
    }
    ll mid = (low+high)/2;
    buildSegmentTree(arr,low,mid,2*index+1);
    buildSegmentTree(arr,mid+1,high,2*index+2);
    segment[index] = max(segment[2*index+1],segment[2*index+2]);
}
ll findMaximum(ll arr[],ll low, ll high,ll start,ll end,ll index)
{
    if(low>=start && high<=end)
        return segment[index];
    if(high<start || low>end)
        return INT_MIN;
    int mid = (low+high)/2;
    return max(findMaximum(arr,low,mid,start,end,2*index+1),findMaximum(arr,mid+1,high,start,end,2*index+2));
}
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    buildSegmentTree(arr,0,n-1,0);
    ll x,y;
    cin>>x>>y;
    ll ans = findMaximum(arr,0,n-1,x,y,0);
    cout<<ans<<endl;
}