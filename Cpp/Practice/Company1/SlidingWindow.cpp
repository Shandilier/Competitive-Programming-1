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
    ll k;
    cin>>k;
    deque<ll>q;
    for(ll i=0;i<k;i++)
    {
        while(!q.empty() && arr[i]>arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for(ll i=k;i<n;i++)
    {
        cout<<arr[q.front()]<<" ";
        while(!q.empty() && arr[q.back()]<arr[i])
        {
            q.pop_back();
        }
        while(!q.empty() && q.front()<=(i-k))
            q.pop_front();
        q.push_back(i);
    }
    cout<<arr[q.front()]<<endl;
    return 0;
}