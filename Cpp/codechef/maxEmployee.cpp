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
typedef pair<ll,ll> ii;

ll solve()
{
    ll x,y;
    ll count=0;
    while(cin>>x>>y)
    {
        count++;
    }
    cout<<count<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll test;
    // int test=1;
    cin>>test;
    ll m=1;
    while(test--)
    {
        cout<<"Case "<<m<<": "<<solve()<<endl;
        m++;
    }
    return 0;
}