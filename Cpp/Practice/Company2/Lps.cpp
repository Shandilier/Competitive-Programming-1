#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s,p;
    cin>>s>>p;
    ll n=s.length();
    ll lps[n];
    memset(lps,0,sizeof(lps));
    lps[0]=0;
    ll i=1;
    ll len=0;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                i++;
            }
            else
            {
                len=lps[len-1];
            }
        }
    }
    // for(ll i=0;i<n;i++)
    //     cout<<lps[i]<<" ";
    // cout<<endl;
    i=0;
    ll j=0;
    ll m=p.length();
    ll count=0;
    while(i<n)
    {
        if(s[i]==p[j])
        {
            i++,j++;
        }
        if(j==m)
        {
            count++;
            j=lps[j-1];
        }
        else if(i<n && s[i]!=p[j])
        {
            if(j==0)
                i++;
            else
            {
                j=lps[j-1];
            }
        }
    }
    cout<<count<<endl;
}