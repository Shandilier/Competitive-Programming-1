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
    ll n;
    cin>>n;
    if(n==0)
    {
        return 0;
    }
    ll arr[n];
    rep(i,n)
        cin>>arr[i];
    ll dp[n];
    memset(dp,1,sizeof(dp));
    dp[0]=arr[0];
    if(n==1)
    {
    	return arr[0];
    }
    dp[1]=arr[1];
    dp[1]=max(dp[1],dp[0]);
    loop(i,2,n)
    {
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
    }
    return dp[n-1]; 
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