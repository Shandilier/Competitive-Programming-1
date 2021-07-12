#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll segmentArray[200001];
ll buildSegmentTree(ll arr[],ll index,ll low,ll high,ll n)
{
    if(low==high)
    {
        segmentArray[index]=segmentArray[low];
        return;
    }
    ll mid = (low+high)/2;
    buildSegmentTree(arr,2*index+1,low,mid-1,n);
    buildSegmentTree(arr,2*index+2,mid+1,high,n);
    segmentArray[index]=max(segmentArray[2*index+1],segmentArray[2*index+2]);
}

ll findRangeMax(ll index,ll low,ll high,ll leftRange,ll rightRange)
{
    if(low>=leftRange && high<=rightRange)
        return seg[index];
    if(high<leftRange || left>rightRange)
        return INT_MIN;
    return max(findRangeMax(2*index+1,low,mid,leftRange,rightRange),findRangeMax(2*index+2,mid+1,high,leftRange,rightRange));
}

int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }   

    buildSegmentTree(arr,0,0,n-1,n);
    ll q;
    cin>>q;
    ll x,y;
    
    for(ll i=0;i<q;i++)
    {
        cin>>x>>y;
        cout<<findRangeMax(0,0,n-1,x,y)<<" ";
    }
}