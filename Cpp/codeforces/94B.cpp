#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll x,y;
        cin>>x>>y;
        ll a,b;
        cin>>a>>b;
        ll sum=0;
        ll val1,val2,val3,val4;

        if(n%a==0)
        {
            val1=a;
            val2=b;
            val3=n;
            val4=m;
        }
        else if(n%b==0)
        {
            val1=b;
            val2=a;
            val3=n;
            val4=m;
        }
        else if(m%a==0)
        {
            val1=a;
            val2=b;
            val3=m;
            val4=n;
        }
        else
        {
            val1=b;
            val2=a;
            val3=m;
            val4=n;
        }
        ll val5,val6,val7,val8;
        if(a>b)
        {
            val5=a;
            val6=b;
            val7=x;
            val8=y;
            if(n%val6==0)

            else if(m%val6==0)
        }
        else
        {
            val5=b;
            val6=a;
            val7=y;
            val8=x;
        }
        if(n%val5==0)
        {
            
        }
        
    }
    return 0;
}