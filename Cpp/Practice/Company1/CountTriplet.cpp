#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr1[n],arr2[n],arr3[n];
    for(ll i=0;i<n;i++)
        cin>>arr1[i];
    for(ll i=0;i<n;i++)
        cin>>arr2[i];
    for(ll i=0;i<n;i++)
        cin>>arr3[i];
    ll i=0,j=0,k=0;
    ll countTriplet=0;
    sort(arr1,arr1+n);
    sort(arr2,arr2+n);
    sort(arr3,arr3+n);
}