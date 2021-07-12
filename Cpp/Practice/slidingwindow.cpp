#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    deque<ll>q;
    ll maxm=0;
    for(ll i=0;i<k;i++)
    {
        while(!q.empty() && arr[i]>=arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for(ll i=k;i<n;i++)
    {
        ll x = arr[i];
        cout<<arr[q.front()]<<" ";
        while(!q.empty() && i-k>=q.front())
        {
            q.pop_front();
        }
        while(!q.empty() && arr[i]>=arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.front()]<<endl;
}
