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
    ll key;
    ll j;
    for(ll i=0;i<n;i++)
    {
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>=key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
