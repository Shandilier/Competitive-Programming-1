#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    ll arr1[n],arr2[n];
    for(ll i=0;i<n;i++)
        cin>>arr1[i];
    for(ll i=0;i<n;i++)
        cin>>arr2[i];
    vector<pair<int,int> >v1;
    vector<pair<int,int> >v2;
    ll diff=0;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(arr1[i]>arr2[i])
        {
            v1.push_back({i+1,arr1[i]-arr2[i]});
            diff+=arr1[i]-arr2[i];
            ans+=arr1[i]-arr2[i];
        }
        else if(arr2[i]>arr1[i])
        {
            v2.push_back({i+1,arr2[i]-arr1[i]});
            diff-=arr2[i]-arr1[i];
        }
    }
    if(diff!=0)
    {
        cout<<-1<<endl;
        return;
    }
    ll i=0,j=0;
    cout<<ans<<endl;
    // for(int i=0;i<v1.size();i++)
    //     cout<<v1[i].first<<" "<<v1[i].second<<endl;
    // for(int i=0;i<v2.size();i++)
    //     cout<<v2[i].first<<" "<<v2[i].second<<endl;
    while(i<v1.size() && j<v2.size())
    {
        cout<<v1[i].first<<" "<<v2[j].first<<endl;
        v1[i].second--;
        v2[j].second--;
        if(v1[i].second==0)
            i++;
        if(v2[j].second==0)
            j++;
        // if(i==v1.size() && j==v2.size())
        //     break;
    }
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