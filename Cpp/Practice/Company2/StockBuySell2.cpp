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
    ll minm=arr[0];
    ll maxm=arr[0];
    ll profit=0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]<maxm)
        {
            profit+=maxm-minm;
            maxm = arr[i];
            minm = arr[i];
        }
        else
        {
            maxm=arr[i];
        }
    }
    profit+=maxm-minm;
    cout<<profit<<endl;
}