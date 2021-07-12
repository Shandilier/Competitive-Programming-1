#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll target;
    cin>>target;
    ll mid,low=0,high=n-1;
    ll ans=-1;
    while(low<=high)
    {
        mid = low+(high-low)/2;
        cout<<low<<" "<<mid<<" "<<high<<endl;
        if(arr[mid]==target)
        {
            ans=mid;
            break;
        }
        else if(arr[low]<arr[mid])
        {
            if(target<arr[low] || target>arr[mid])
                low=mid+1;
            else
            {
                high=mid-1;
            }
        }
        else if(arr[low]>arr[mid])
        {
            if(target<arr[low] && target>arr[mid])
                low=mid+1;
            else
            {
                high=mid-1;
            }
        }
        else
        {
            ll flag=0;
            for(ll i=0;i<mid-1;i++)
            {
                if(arr[i]!=arr[i+1])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            
        }
        
    }
    cout<<ans<<endl;
}