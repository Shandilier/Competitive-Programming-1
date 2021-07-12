#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll A[n],B[n];
    for(ll i=0;i<n;i++)
        cin>>A[i];
    for(ll j=0;j<n;j++)
        cin>>B[j];
    ll sum=0;
    ll index=0;
    for(ll i=0;i<n;i++)
    {
        sum+=(A[i]-B[i]);
    }
    // if(sum<0)
    //     return -1;
    for(ll i=0;i<n;i++)
    {
        sum+=(A[i]-B[i]);
        else if(A[i]<B[i])
        {
            if(sum<0)
            {
                sum=0;
                index=i+1;
            }
        }
    }
    cout<<index<<endl;
    return 0;
}