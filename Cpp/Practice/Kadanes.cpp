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
    ll arr[n];
    rep(i,n)
        cin>>arr[i];
    ll maxm=0,gmax=0;
    rep(i,n)
    {
        maxm=max(maxm+arr[i],arr[i]);
        gmax=max(maxm,gmax);
    }
    cout<<gmax<<endl;
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