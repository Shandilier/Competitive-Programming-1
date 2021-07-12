#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll powerFunction(ll a, ll b, ll mod)
{
    ll res = 1;
    while(b>0)
    {
        if(b&1)
        {
            b--;
            res=res*a;
        }
        b/=2;
        a = a*a;
    }
    return res;
}
int main()
{
    ll a,b,mod;
    cin>>a>>b;
    mod = 1000000007;
    cout<<powerFunction(a,b,mod)<<endl;
}
