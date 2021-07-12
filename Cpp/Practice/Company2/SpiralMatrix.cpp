#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll arr[n][m];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
    }
    ll k=0,l=0;
    while(k<n && l<m)
    {
        for(ll i=l;i<m;i++)
        {
            cout<<arr[k][i]<<" ";
        }
        k++;
        for(ll i=k;i<n;i++)
        {
            cout<<arr[i][m-1]<<" ";
        }
        m--;
        for(ll i=m-1;i>=l;i--)
        {
            cout<<arr[n-1][i]<<" ";
        }
        n--;
        for(ll i=n-1;i>=k;i--)
        {
            cout<<arr[i][l]<<" ";
        }
        l++;
    }
}
