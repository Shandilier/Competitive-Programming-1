#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    ll x;
    priority_queue<ll>max_heap;
    priority_queue<ll,vector<ll>,greater<ll> >min_heap;
    cin>>x;
    max_heap.push(x);
    ll median;
    median = x;
    cout<<median<<endl;
    for(ll i=1;i<n;i++)
    {
        cin>>x;
        if(max_heap.size()>min_heap.size())
        {
            if(median>x)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(x);
            }
            else
            {
                min_heap.push(x);
            }
            median = (max_heap.top()+min_heap.top())/2;
        }
        else if(max_heap.size()<min_heap.size())
        {
            if(median>x)
            {
                max_heap.push(x);
            }
            else
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(x);
            }
            median = (max_heap.top()+min_heap.top())/2;
        }
        else
        {
            if(median>x)
            {
                max_heap.push(x);
                median = max_heap.top();
            }
            else
            {
                min_heap.push(x);
                median = min_heap.top();
            }
        }
        cout<<median<<endl;
    }
}