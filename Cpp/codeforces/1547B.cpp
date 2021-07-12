#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;

        cin>>s;
        ll n=s.length();
        if(n==1 && s[0]=='a')
        {
            cout<<"YES"<<endl;
            continue;
        }
        ll i=0;
        for(;i<s.length();i++)
        {
            if(s[i]=='a')
            {
                break;
            }
        }
        ll j=i-1;
        ll k=i+1;
        ll a=0,b=0,c=0;
        ll flag=0;
        // cout<<index<<endl;
        while(1)
        {
            a = s[i]-'0';
            if(j>=0)
            {
                b = s[j]-'0';
            }
            if(k<n)
            {
                c = s[k]-'0';
            }
            if(b==a+1)
            {
                i=j;
                j--;
            }
            else if(c==a+1)
            {
                i=k;
                k++;
            }
            else
            {
                flag=1;
                break;
            }
            if(j<0 && k>=n)
                break;
            // cout<<i<<" "<<j<<" "<<k<<endl;
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }  
    }
    return 0;
}