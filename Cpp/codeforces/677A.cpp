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
    vector<ll>v;
    for(ll i=0;i<9;i++)
    {
        ll val=i+1;
        v.push_back(val);
        val=val*10+(i+1);
        v.push_back(val);
        val=val*10+(i+1);
        v.push_back(val);
        val=val*10+(i+1);
        v.push_back(val);
    }
    ll sum=0;
    ll i=0;
    while(i<v.size() && v[i]<=n)
    {
        while(v[i]>0)
        {
            sum+=(v[i]%10);
            v[i]/=10;
        }
        i++;
    }
    cout<<sum<<endl;
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