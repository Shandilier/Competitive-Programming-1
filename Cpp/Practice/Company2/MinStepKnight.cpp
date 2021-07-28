#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n][n];
    memset(arr,0,sizeof(arr));
    ll x[8]={1,-1,2,-2,-1,1,-2,2};
    ll y[8]={2,2,1,1,-2,-2,-1,-1};
    ll a,b;
    cin>>a>>b;
    if(a<0 || b<0 || a>=n || b>=n)
    {
        cout<<0<<endl;
        return 0;
    }
    queue<pair<ll,pair<ll,ll> > >q;
    q.push({0,{a,b}});
    pair<ll,pair<ll,ll> >p;
    ll xnew,ynew;
    while(!q.empty())
    {   
        p = q.front();
        q.pop();
        ll xcurr = p.second.first;
        ll ycurr = p.second.second;
        if(xcurr>=n || ycurr>=n || xcurr<0 || ycurr<0)
        {
            cout<<p.first<<endl;
            break;
        }
        ll flag=0;
        for(ll i=0;i<8;i++)
        {
            xnew = x[i]+xcurr;
            ynew = y[i]+ycurr;
            if(xnew<0 || xnew>=n || ynew<0 || ynew>=n)
            {
                flag=1;
                break;
            }
            if(arr[xnew][ynew]==0)
            {
                arr[xnew][ynew]=1;
                q.push({p.first+1,{xnew,ynew}});
            }
        }
        if(flag==1)
        {
            cout<<p.first+1<<endl;
            break;
        }
    }
    return 0;
}