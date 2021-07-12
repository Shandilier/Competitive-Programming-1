#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s,p;
    cin>>s>>p;
    ll n=s.length();
    ll m=p.length();
    ll lps[n];
    lps[0]=0;
    ll len=0,i=1;
    while(i<n)
    {
        // cout<<i<<" "<<len<<endl;
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len-1>=0)
                len = lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    i=0;
    int j=0;
    while(i<n)
    {
        if(s[i]==p[j])
        {
            i++,j++;
        }
        if(j==m)
        {
            cout<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<n && s[i]!=p[j])
        {
            if(j>0)
            {
                j=lps[j-1];
            }
            else
            {
                j=0;
                i++;                
            }
        }
    }
    for(ll i=0;i<n;i++)
        cout<<lps[i]<<" ";
    cout<<endl;
}

Complex add(Complex & c)
{
    Complex temp;
    temp.a = a
}
c3 = c1.add(C2);