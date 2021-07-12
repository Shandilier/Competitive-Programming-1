#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void heapify(ll arr[],ll n,ll i)
{
    // cout<<i<<endl;
    if(i>=n)
        return;
    ll left = 2*i+1;
    ll right = 2*i+2;
    ll largest = i;
    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
int main()
{`
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    for(ll i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(ll i=n-1;i>=0;i--)
    {
        cout<<arr[0]<<" ";
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
    // for(ll i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
    cout<<endl;
}