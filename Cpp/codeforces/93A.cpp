#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        ll z=-1;
        for(ll i=2;i<n;i++)
        {
            if(arr[0]+arr[1]<=arr[i])
            {
                z=i+1;
                break;
            }
        }
        if(z==-1)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<1<<" "<<2<<" "<<z<<endl;
        }
        
    }
}
