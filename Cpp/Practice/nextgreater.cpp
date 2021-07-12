#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll next_greater[n];
    stack<ll>s;
    next_greater[n-1]=-1;
    for(ll i=n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            next_greater[i]=-1;
        }
        else
        {
            next_greater[i]=s.top();
        }
        s.push(arr[i]);
    }
    for(ll i=0;i<n;i++)
        cout<<next_greater[i]<<" ";
    cout<<endl;
}