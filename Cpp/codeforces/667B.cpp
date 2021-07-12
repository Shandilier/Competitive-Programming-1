#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        ll prod1,prod2;
        ll minm=1000000000*1000000000;
        if(b>a)
        {
            swap(a,b);
            swap(x,y);
        }
        if(a==b)
        {
            if(x>y)
            {
                swap(x,y);
            }
        }
        cout<<x<<" "<<y<<endl;
        ll diff1= a-x;
        ll diff2=b-y;

        if(diff1>=n)
        {
            a-=n;
            n=0;
        }
        else
        {
            n-=diff1;
            a-=diff1;
            if(diff2>=n)
            {
                b-=n;
            }
            else
            {
                b-=diff2;
            }
        }
        
        cout<<a*b<<endl;
    }
}
