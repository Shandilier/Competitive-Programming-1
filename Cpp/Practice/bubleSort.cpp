#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll minm;
    for(ll i=0;i<n;i++)
    {
        minm = i;
        for(ll j=i+1;j<n;j++)
        {
            if(arr[minm]>arr[j])
                minm = j;
        }
        swap(arr[minm],arr[i]);
    }
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int *func()
{

}

Hashmap<int,int>hm = new Hashmap<>();
Map.entrySet :
