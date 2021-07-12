#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(arr[0]==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll maxStep=arr[0],i=1;

    ll jump=1;
    ll step=arr[0];
    ll flag=0;
    while(i<n)
    {
        if(i==n-1)
        {
            flag=1;
            break;
        }
        step--;
        maxStep = max(maxStep,i+arr[i]);
        if(step==0)
        {
            jump++;
            if(i>=maxStep)
                break;
            step = maxStep-i;
        }
        
        i++;
    }
    if(flag==1)
        cout<<jump<<endl;
    else
        cout<<-1<<endl;
}