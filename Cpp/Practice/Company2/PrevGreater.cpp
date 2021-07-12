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
    ll prevGreater[n];
    for(ll i=0;i<n;i++)
    {
        while(!s.empty() && arr[i]>=s.top())
        {
            s.pop();
        }
        if(s.empty())
            prevGreater[i]=-1;
        else
        {
            prevGreater[i]=s.top();
        }
        s.push(arr[i]);
    }
    for(ll i=0;i<n;i++)
        cout<<prevGreater[i]<<" ";
    cout<<endl;
}