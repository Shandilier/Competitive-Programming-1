#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll k,n,m;
        cin>>k>>n>>m;
        ll arr1[n];
        ll arr2[m];
        for(ll i=0;i<n;i++)
            cin>>arr1[i];
        for(ll i=0;i<m;i++)
            cin>>arr2[i];
        int maxLine = k;
        ll i=0,j=0;
        vector<ll>v;
        ll flag=0;
        while(i<n || j<m)
        {
            if(i<n && arr1[i]==0)
            {
                v.push_back(0);
                maxLine++;
                i++;
            }
            else if(j<m && arr2[j]==0)
            {
                v.push_back(0);
                maxLine++;
                j++;
            }
            else if(i<n && arr1[i]<=maxLine)
            {
                v.push_back(arr1[i]);
                i++;
            }
            else if(j<m && arr2[j]<=maxLine)
            {
                v.push_back(arr2[j]);
                j++;
            }
            else
            {
                flag=1;
                break;
            }
        
        }
        if(flag)
        {
            cout<<-1<<endl;
        }
        else
        {
            for(ll i=0;i<v.size();i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}