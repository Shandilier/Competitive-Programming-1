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
void solve()
{
    ll n;
    cin>>n;
    set<ll>s;
    ll maxm=INT_MIN;
    ll ans;
    vector<ll>v;
    rep(i,n)
    {
        ll x;
        cin>>x;
        v.push_back(x);
        s.insert(x);
    }
    maxm=v[0];
    for(ll i=1;i<n;i++)
    {
        if(maxm<v[i])
        {
            maxm=v[i];
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(i==0)
        {
            if(v[i]==maxm && v[i+1]!=maxm)
            {
                cout<<i+1<<endl;
                return;
            }
        }
        else if(i==n-1)
        {
            if(v[i]==maxm && v[i-1]!=maxm)
            {
                cout<<i+1<<endl;
                return;
            }
        }
        else
        {
            if(v[i]==maxm && (v[i+1]!=maxm || v[i-1]!=maxm))
            {
                cout<<i+1<<endl;
                return;
            }
        }  
    }
    if(s.size()==1)
    {
        cout<<-1<<endl;
    }

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