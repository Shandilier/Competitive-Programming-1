#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s;
    string p;
    cin>>s;
    cin>>p;
    ll countP[256]={0},countS[256]={0};
    for(ll i=0;i<p.length();i++)
        countP[p[i]-'0']++;
    ll minLength=INT_MAX;
    ll start=0;
    ll count=0;
    ll m = p.length();
    if(m>s.length())
    {
        cout<<-1<<endl;
        return 0;
    }
    // for(ll i=0;i<m;i++)
    // {
    //     countS[s[i]-'0']++;
    //     if(countS[i])
    // }
    ll ans=0;
    for(ll i=0;i<s.length();i++)
    {
        countS[s[i]-'0']++;
        if(countP[s[i]-'0']==countS[s[i]-'0'])
        {
            count++;
        }
        if(count==m)
        {
            // ans++;
            while(countS[s[start]-'0']>countP[s[start]-'0'])
            {
                countS[s[start]-'0']--;
                start++;
            }
            minLength=min(minLength,i-start+1);
            
        }
    }
    cout<<minLength<<endl;
    return 0;
}