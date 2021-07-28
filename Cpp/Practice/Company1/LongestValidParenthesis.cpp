#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll n=s.length();
    ll dp[n]={0};
    memset(dp,0,sizeof(dp));
    ll maxm=0;
    for(ll i=1;i<n;i++)
    {
        if(s[i]==')')
        {
            if(s[i-1]=='(')
            {
                dp[i]=(i>=2?dp[i-2]:0)+2;
            }
            else if(s[i-1]==')' && i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
            {
                dp[i]=(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0)+dp[i-1]+2;
            }
        }
        maxm=max(maxm,dp[i]);
    }
    cout<<maxm<<endl;
}

// GERITM23885052
// https://ge.ent.box.com/s/372eeul2t71q7yemwg9eaybqz6oyr4ie/file/677983483819


