#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll calc(ll n)
{
    ll count = 0;
    while (n > 0)
    {
        if (n % 10 == 2 || n % 10 == 0 || n % 10 == 4)
            count++;
        n = n / 10;
    }
    return count;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll count = 0 ; 
        for (ll i = 2; i <= n; i++)
            count += calc(i); 
        cout<<count+1<<endl;      
    }
    return 0;
}