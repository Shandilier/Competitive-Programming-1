#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr1[n],arr2[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(ll i=0;i<n;i++)
        cin>>arr2[i];
    sort(arr1,arr1+n);
    sort(arr2,arr2+n);
    ll x;
    cin>>x;
    ll i=0,j=n-1;
    ll diff = INT_MAX;
    while(i<n && j>=0)
    {
        if(arr1[i]+arr2[j]>=x)
        {
            diff = min(diff,abs(arr1[i]+arr2[j]-x));
            j--;
        }
        else
        {
            diff = min(diff,abs(x-arr1[i]-arr2[j]));
            i++;
        }
    }
    cout<<diff<<endl;
}