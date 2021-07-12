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
typedef pair<long long int,long long int> ii;
void solve()
{
    ll n;
    cin>>n;
    // if(n>=40)
    // {
    //     cout<<-1<<endl;
    //     return;
    // }
    // if(n==39)
    // {
    //     cout<<456789<<endl;
    //     return;
    // }
    loop(i,1,999996)
    {
        ll val = i;
        ll sum=0;
        unordered_map<ll,ll>m;
        ll flag=0;
        // cout<<val<<endl;
        while(val)
        {
            ll rem = val%10;
            if(m.find(rem)!=m.end())
            {
                flag=1;
                break;
            }
            sum+=rem;
            m[rem]=1;
            val/=10;
            // cout<<val<<endl;
        }
        m.clear();
        // cout<<endl;
        if(sum==n && flag!=1)
        {
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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
