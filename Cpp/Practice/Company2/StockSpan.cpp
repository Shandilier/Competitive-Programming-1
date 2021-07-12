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
    ll flag=0;
    for(ll i=0;i<n;i++)
    {
        flag=0;
        while(!s.empty() && arr[i]>arr[s.top()])
        {
            s.pop();
            flag=1;
        }
        if(!s.empty())
            cout<<i-s.top()<<endl;
        else if(s.empty())
            cout<<i+1<<endl;
        else if(flag==1)
            cout<<1<<endl;
        s.push(i);
    }
}