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
        vector<int>v;
        ll count=0;
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                count++;
            else
            {
                v.push_back(count);
                count=0;
            }
        }
        if(count>0)
        {
            v.push_back(count);
        }
        sort(v.begin(),v.end());
        ll sum=0;
        int flag=0;
        for(ll i=v.size()-1;i>=0;i--)
        {
            // cout<<v[i]<<" ";
            if(flag%2==0)
            {
                sum+=v[i];
                flag=1;
            }
            else
            {
                flag=0;
            }
            
        }
        cout<<sum<<endl;
    }
}