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
    ll a,b,c;
    cin>>a>>b>>c;
    ll sum=a+b+c;
    ll val = sum/7;
    if(val==0)
    {
        cout<<"NO"<<endl;
        return;
    }
    sum-=(val*3);
    ll minm=min(min(a,b),c);
    if(sum%6==0)
    {
        if(minm>=val)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
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