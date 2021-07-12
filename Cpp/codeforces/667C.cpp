#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        vector<ll>v;
        cin>>n>>x>>y;
        ll diff = y-x;
        if(diff==1)
        {
            
        }
        ll ans=-1;
        for(ll i=1;i<=diff;i++)
        {
            if(i<=n-1 && diff%i==0)
            {
                ans = i;
            }
        }
        cout<<ans<<endl;
        if(ans==-1)
        {
            ll temp = x;
            ll val1 = n-2;
            while(temp>0 && val1>0)
            {
                if(temp-diff>0)
                {
                    temp-=diff;
                    val1--;
                }
                else
                {
                    break;
                }
            }
            while(1)
            {
                if(temp==y)
                {
                    v.push_back(temp);
                    temp+=diff;
                    break;
                }
                else
                {
                    v.push_back(temp);
                    temp+=diff;
                }
            }
            while(val1--)
            {
                v.push_back(temp);
                temp+=diff;
            }
        }
        else
        {
            ll val = diff / ans;
            ll val1 = n-1-ans;
            ll temp = x;
            while(val1>0 && temp>0)
            {
                if(temp-val>0)
                {
                    temp-=val;
                    val1--;
                }
                else
                {
                    break;
                }
            }
            while(1)
            {
                if(temp==y)
                {
                    v.push_back(temp);
                    temp+=val;
                    break;
                }
                else
                {
                    v.push_back(temp);
                    temp+=val;
                }
            }
            while(val1>0)
            {
                v.push_back(temp);
                temp+=val;
                val1--;
            }
        } 
        for(ll i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl; 
    }

}