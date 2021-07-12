#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    // ll n;
    // cin>>n;
    string s;
    cin>>s;
    ll n=s.length();
    if(n%2==1)
    {
        cout<<-1<<endl;
        return;
    }
    ll count1=0,count2=0;
    for(ll i=0;i<n-2;i++)
    {
        if(s[i]==s[i+1] && s[i+1]==s[i+2])
        {
            cout<<-1<<endl;
            return;
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='1')
            count1++;
        else
        {
            count2++;
        }
        
    }
    cout<<abs(count1-count2)/2<<endl;
    
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
