#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>ram;
    vector<ll>shyam;
    vector<ll>both;
    ll x,y,z;
    
    for(ll i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        if(y==0 && z==0)
            continue;
        else if(y==1 && z==0)
            ram.push_back(x);
        else if(y==0 && z==1)
            shyam.push_back(x);
        else if(y==1 && z==1)
            both.push_back(x);
    }
    sort(ram.begin(),ram.end());
    sort(shyam.begin(),shyam.end());
    sort(both.begin(),both.end());
    if(ram.size()+shyam.size()+both.size()<2*k)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll ans=0;
    ll i=0,j=0,m=0,flag=0;
    ll ramCount=0,shyamCount=0;
    while(i<ram.size() && j<shyam.size() && m<both.size())
    {
        if(ramCount==k && shyamCount==k)
        {
            flag=1;
            break;
        }
        if(ram[i]+shyam[j]>both[m])
        {
            ans+=both[m];
            ramCount++,shyamCount++,m++;
        }
        else
        {
            ans+=ram[i];
            ans+=shyam[j];
            i++,j++,ramCount++,shyamCount++;
        }
    }
    if(flag==1)
    {
        cout<<ans<<endl;
        return 0;
    }
    cout<<m<<endl;
    if(m==both.size())
    {
        while(i<ram.size() && ramCount!=k)
        {
            ans+=ram[i];
            i++;
            ramCount++;
        }
        while(j<shyam.size() && shyamCount!=k)
        {
            ans+=shyam[j];
            j++;
            shyamCount++;
        }
        if(ramCount==k && shyamCount==k)
        {
            cout<<ans<<endl;
            return 0;
        }
        else
        {
            cout<<-1<<endl;
        }    
    }
    else
    {
       while(m<both.size())
       {
           if(ramCount==k && shyamCount==k)
           {
               flag=1;
               break;
           }
           ans+=both[m];
           ramCount++;
           shyamCount++;
           m++;
           cout<<m<<endl;
       }
        if(ramCount==k && shyamCount==k)
            cout<<ans<<endl;
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}