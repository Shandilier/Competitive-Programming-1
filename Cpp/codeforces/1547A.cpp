#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        ll ans=abs(x2-x1)+abs(y2-y1);
        // cout<<ans<<endl;
        if((x1==x2 && x2==x3 && ((y3>y1 && y3<y2) || (y3<y1 && y3>y2)) ) || ((y1==y2 && y2==y3) && ((x3<x1 && x3>x2) || (x3>x1 && x3<x2))))
        {
            ans+=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}