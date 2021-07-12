#include<bits/stdc++.h>
#define ll          long long int
#define loop(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n)    for(int (i)=0;(i)<n;(i)++)
#define bp          1000000007
#define sz(a)       int((a).size())
#define pb          push_back
#define mp          make_pair
#define all(c)      (c).begin(),(c).end()
#define F           first
#define S           second
using namespace std;
typedef pair<int,int> ii;
ll calc(ll a=7,ll b=10)
{
    return a+b;
}
void solve()
{
    // ll n;
    // cin>>n;
    // ll arr[n];
    // rep(i,n)
    //     cin>>arr[i];
    // map<ll,vector<ll> >m;
    // for(ll i=0;i<n;i++)
    // {
    //     m[arr[i]].push_back(i+1);
    // }
    // map<ll,vector<ll> > ::iterator it;
    // map<ll,vector<ll> > ::iterator it1;
    // vector<ii>ans;
    // ll flag=0;
    // ll flag1=0;
    // for(it=m.begin();it!=m.end();it++)
    // {
    //     for(it1=m.begin();it1!=m.end();it1++)
    //     {
    //         if(it==it1)
    //             continue;
    //         vector<ll>v1 = it->second;
    //         vector<ll>v2 = it1->second;
    //         ans.push_back({v1[0],v2[0]});
    //         if(ans.size()==n-1)
    //         {
    //             flag1=1;
    //             break;
    //         }
    //     }
    //     if(flag1==1)
    //         break;
    // }
    // if(flag1==1)
    // {
    //     cout<<"YES"<<endl;
    //     for(ll i=0;i<ans.size();i++)
    //     {
    //         cout<<ans[i].first<<" "<<ans[i].second<<endl;
    //     }
    //     return;
    // }
    // for(it=m.begin();it!=m.end();it++)
    // {
    //     for(it1=m.begin();it1!=m.end();it1++)
    //     {
    //         if(it==it1)
    //             continue;
    //         vector<ll>v1 = it->second;
    //         vector<ll>v2 = it1->second;
    //         for(ll i=0;i<v1.size();i++)
    //         {
    //             for(ll j=1;j<v2.size();j++)
    //             {
    //                 ans.push_back({v1[i],v2[j]});
    //                 if(ans.size()==n-1)
    //                 {
    //                     flag=1;
    //                     break;
    //                 }
    //             }
    //             if(flag==1)
    //                 break;
    //         }
    //         if(flag==1)
    //             break;
    //     }
    //     if(flag==1)
    //         break;
    // }
    // if(flag==0)
    // {
    //     cout<<"NO"<<endl;
    // }
    // else
    // {
    //     cout<<"YES"<<endl;
    //     for(ll i=0;i<ans.size();i++)
    //     {
    //         cout<<ans[i].first<<" "<<ans[i].second<<endl;
    //     }
    // }
    cout<<calc(6,7)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll test;
    // int test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}