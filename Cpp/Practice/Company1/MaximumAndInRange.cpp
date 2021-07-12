#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<pair<ll,ll> >tree;
void buildSegmentTree(ll index,ll low,ll high,ll arr[])
{
    // cout<<index<<endl;
    if(low==high)
    {
        tree[index].first = arr[low];
        tree[index].second = 1;
        return;
    }
    ll mid = (low+high)/2;
    buildSegmentTree(2*index+1,low,mid,arr);
    buildSegmentTree(2*index+2,mid+1,high,arr);
    if(tree[2*index+1].first>tree[2*index+2].first)
    {
        tree[index].first = tree[2*index+1].first;
        tree[index].second = max(tree[2*index+2].first,max(tree[2*index+1].second,tree[2*index+2].second));
    }
    else
    {
        tree[index].first = tree[2*index+2].first;
        tree[index].second = max(tree[2*index+1].first,max(tree[2*index+1].second,tree[2*index+2].second));
    }
}
pair<ll,ll> find2MaxValues(ll index,ll low,ll high,ll l,ll r)
{
    if(low>r || high<l)
    {
        pair<ll,ll>p;
        p.first = INT_MIN;
        p.second = INT_MIN;
        return p;
    }
    if(low>=l && high<=r)
        return tree[index];
    ll mid = (low+high)/2;
    pair<ll,ll>p1,p2;
    pair<ll,ll>p;
    p1 = find2MaxValues(2*index+1,low,mid,l,r);
    p2 = find2MaxValues(2*index+2,mid+1,high,l,r);
    if(p1.first>p2.first)
    {
        p.first =p1.first;
        p.second = max(p2.first,max(p1.second,p2.second));
        return p; 
    }
    else
    {
        p.first = p2.first;
        p.second = max(p1.first,max(p1.second,p2.second));
        return p;
    }
}
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll count=0;
    ll m=n;
    ll size = pow(2,n);
    // ll size = 1<<count;
    // cout<<size<<endl;
    tree.resize(size);
    buildSegmentTree(0,0,n-1,arr);
    // cout<<"Helo"<<endl;
    ll ans=INT_MIN;
    ll start=INT_MAX,end=INT_MAX;
    pair<ll,ll>p;
    // for(ll i=0;i<size;i++)
    //     cout<<tree[i].first<<" "<<tree[i].second<<endl;
    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            // cout<<i<<" "<<j<<endl;
            p = find2MaxValues(0,0,n-1,i,j);
            ll x =p.first;
            ll y=p.second;
            cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
            if((x&y)>ans)
            {
                ans=x&y;
                start = i;
                end=j;
            }
            else if((x&y)==ans)
            {
                if(start>x)
                {
                    start=x;
                    end = y;
                }
                else if(start==x)
                {
                    if(end>y)
                    {
                        end=y;
                    }
                }
            }
        }
    }
    cout<<ans<<" "<<start<<" "<<end<<endl;
    return 0;
}