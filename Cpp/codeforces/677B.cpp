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
    ll arr[n];
    rep(i,n)
        cin>>arr[i];
    ll count=0;
    ll i=0;
    for(;i<n;i++)
    {
        if(arr[i]==1)
            break;
    }
    ll j=n-1;
    for(;j>i;j--)
    {
        if(arr[j]==1)
            break;
    }
    for(ll k=i+1;k<j;k++)
    {
        if(arr[k]==0)
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
    while(test--)
    {
        solve();
    }
    return 0;
}