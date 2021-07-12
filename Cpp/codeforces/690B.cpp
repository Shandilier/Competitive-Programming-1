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
    string s;
    cin>>s;
    // cout<<"Hello"<<endl;
    if(s[0]=='2' && s[n-3]=='0' && s[n-2]=='2' && s[n-1]=='0')
    {
        cout<<"YES"<<endl;
        return;
    }
    if(s[0]=='2' && s[1]=='0' && s[n-2]=='2' && s[n-1]=='0')
    {
        cout<<"YES"<<endl;
        return;
    }
    if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[n-1]=='0')
    {
        cout<<"YES"<<endl;
        return;
    }
    if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[3]=='0')
    {
        cout<<"YES"<<endl;
        return;
    }
    if(s[n-4]=='2' && s[n-3]=='0' && s[n-2]=='2' && s[n-1]=='0')
    {
        cout<<"YES"<<endl;
        return;
    }
    
    cout<<"NO"<<endl;
    
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

