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
    string s;
    cin>>s;
    ll n = s.length();
    ll i=0;
    ll flag=0;
    // cout<<n<<endl;
    for(ll i=0;i<n;i++)
    {
        if(flag==0)
        {
            if(s[i]=='a')
            {
                s[i]='b';
            }
            else
            {
                s[i]='a';
                
            }
            flag=1;
        }
        else
        {
            if(s[i]=='z')
            {
                s[i]='y';
            }
            else
            {
                s[i]='z';
                
            }
            flag=0;
        }
        // cout<<i<<endl;
        
    }
    cout<<s<<endl;
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