#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin>>s;
    ll count1=0,count2=0;
    ll ans=0;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            if(count1<0)
                count1=0;
            count1++;
        }
        else if(s[i]==')')
        {
            if(count1>0)
            {
                ans++;
            }
            count1--;
        }
        else if(s[i]=='[')
        {
            if(count2<0)
                count2=0;
            count2++;
        }
        else if(s[i]==']')
        {
            if(count2>0)
            {
                ans++;
            }
            count2--;
        }
    }
    cout<<ans<<endl;
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