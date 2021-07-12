#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    priority_queue<ll>maxm;
    priority_queue<ll,vector<ll>,greater<ll> >minm;
    ll n;
    cin>>n;
    ll x;
    double median;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        if(i==0)
        {
            maxm.push(x);
            median=x;
        }
        else if(maxm.size()>minm.size())
        {
            if(maxm.top()>x)
            {
                minm.push(maxm.top());
                maxm.pop();
                maxm.push(x);
            }
            else
            {
                minm.push(x);
            }
            median=(maxm.top()+minm.top())/2.0;
        }
        else if(minm.size()>maxm.size())
        {
            if(minm.top()>x)
            {
                maxm.push(x);
            }
            else
            {
                maxm.push(minm.top());
                minm.pop();
                minm.push(x);
            }
            median=(maxm.top()+minm.top())/2.0;           
        }
        else
        {
            if(x>median)
            {
                minm.push(x);
                median = minm.top();
            }
            else
            {
                maxm.push(x);
                median=maxm.top();
            }
        }
        cout<<median<<endl;
        
    }
    return 0;
}