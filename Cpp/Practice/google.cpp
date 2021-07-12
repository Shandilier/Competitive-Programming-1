#include <bits/stdc++.h> 
#define ll long long int
using namespace std; 
 
ll *st; 

ll findGcd(ll ss, ll se, ll qs, ll qe, ll si) 
{ 
    if (ss>qe || se < qs) 
        return 0; 
    if (qs<=ss && qe>=se) 
        return st[si]; 
    ll mid = ss+(se-ss)/2; 
    return __gcd(findGcd(ss, mid, qs, qe, si*2+1), 
               findGcd(mid+1, se, qs, qe, si*2+2)); 
} 

ll findRangeGcd(ll ss, ll se, ll arr[],ll n) 
{ 
    return findGcd(0, n-1, ss, se, 0); 
} 

ll constructST(ll arr[], ll ss, ll se, ll si) 
{ 
    if (ss==se) 
    { 
        st[si] = arr[ss]; 
        return st[si]; 
    } 
    ll mid = ss+(se-ss)/2; 
    st[si] = __gcd(constructST(arr, ss, mid, si*2+1), 
                 constructST(arr, mid+1, se, si*2+2)); 
    return st[si]; 
} 
ll *constructSegmentTree(ll arr[], ll n) 
{ 
   ll height = (ll)(ceil(log2(n))); 
   ll size = 2*(ll)pow(2, height)-1; 
   st = new ll[size]; 
   constructST(arr, 0, n-1, 0); 
   return st; 
} 
ll primeFactors(int n)  
{  
    set<ll>s;
    while (n % 2 == 0)  
    {  
        s.insert(2);  
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            s.insert(i);  
            n = n/i;  
        }  
    }  
    if (n > 2)  
        s.insert(n);
    return s.size();
}  
int main() 
{ 
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        ll q;
        cin>>q;

        constructSegmentTree(a, n); 
        ll x,y;
        while(q--)
        {
            cin>>x>>y;
            ll gcd = findRangeGcd(x-1, y-1, a, n);
            ll count=primeFactors(gcd);
            cout<<count<<endl;
        }        
    }
    return 0; 
} 


int height(Node *root)
{
    if(!root)
        return 0;
    return 1+max(height(root->left),height(root->right));
}