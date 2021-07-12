#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll n=s.length();
    bool p[n][n];
    ll c[n][n];
    for(ll i=0;i<n;i++)
    {
        p[i][i]=true;
        c[i][i]=0;
    }
    for(ll k=2;k<=n;k++)
    {
        for(ll i=0;i<n-k+1;i++)
        {
            ll j = i+k-1;
            if(k==2)
            {
                p[i][j]=(s[i]==s[j]);
            }
            else
            {
                p[i][j]=(s[i]==s[j] && p[i+1][j-1]);
            }
            if(p[i][j])
                c[i][j]=0;
            else
            {
                c[i][j]=INT_MAX;
                for(ll m=i;m<j;m++)
                {
                    c[i][j]=min(c[i][j],c[i][m]+c[m+1][j]+1);
                }
            }       
        }
    }
    cout<<c[0][n-1]<<endl;
}