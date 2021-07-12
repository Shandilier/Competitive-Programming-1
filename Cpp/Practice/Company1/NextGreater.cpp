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
    stack<ll>s;
    ll nextGreater[n];
    for(ll i=n-1;i>=0;i--)
    {
        while(!s.empty() && arr[i]>=s.top())
        {
            s.pop();
        }
        if(s.empty())
            nextGreater[i]=-1;
        else
        {
            nextGreater[i]=s.top();
        }
        s.push(arr[i]);
    }
    for(ll i=0;i<n;i++)
        cout<<nextGreater[i]<<" ";
    cout<<endl;
}