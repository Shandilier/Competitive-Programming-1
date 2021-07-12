#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll diff = abs(a-b);
        ll arr[10];
        for(ll i=0;i<10;i++)
            arr[i]=i+1;
        ll count=0;
        ll i=9;
        while(diff>0)
        {
            if(arr[i]<=diff)
            {
                ll val = diff/arr[i];
                count+=val;
                diff-=val*arr[i];
            }
            i--;
        }
        cout<<count<<endl;
    }
}
