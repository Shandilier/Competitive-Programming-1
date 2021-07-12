#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    char s[n];
    for(ll i=0;i<n;i++)
        cin>>s[i];
    ll i=n-1;
    while(i>=1)
    {
        if(s[i]<s[i-1])
            i--;
        else
        {
            break;
        }
    }
    char key = s[i-1];
    char minm=s[i];
    ll index=i;
    for(ll j=i;j<n;j++)
    {
        if(s[j]>key && s[j]<minm)
        {
            minm=s[j];
            index=j;
        }
    }
    for(ll j=0;j<n;j++)
        cout<<s[j];
    swap(s[index],s[i-1]);
    sort(s+i,s+n);
    for(ll j=0;j<n;j++)
        cout<<s[j];
    cout<<endl;    
    return 0;
}