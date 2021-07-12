#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vois solve()
{
    ll n;
    cin>>n;
    ll arr[n][n];
    for(ll i=0;i<n;i++)   // input
    {
        for(ll j=0;j<n;j++)
            cin>>arr[i][j];
    }
    if(n==1)
    {
        cout<<"It is a magic matrix"<<endl;
        return;
    }
    bool result=true;   // final answer
    ll sum;
    ll initial_value;   // initial result
    ll column_sum[n];
    memset(column_sum,0,sizeof(n));  
    
    for(ll i=0;i<n;i++)
    {
        sum=0;
        for(ll j=0;j<n;j++)
        {
            sum+=arr[i][j];
            column_sum[j]+=arr[i][j];   // 
            
        }
        if(i==0)
        {
            initial_value=sum;
        }
        else
        {
            if(initial_value!=sum)
            {
                result=false;
                break;
            }
        }
    }
    for(ll i=0;i<n-1;i++)
    {
        if(column_sum[i]!=column_sum[i+1])
        {
            result=false;
            break;
        }
    }
    if(result==false)
    {
        cout<<"Not a magic matrix"<<endl;
        return;
    }

    
    cout<<"It is a magic matrix"<<endl;
}
int main()
{
    solve();
    return 0;
}

2 7 6    
9 5 1
4 3 8
arr_column=[0,0,0] 
arr_column =[2,7,6];  row0
arr_column = [9+2, 5+7, 1+6]
            = [11,12,7]   : row1

arr_column = [4+11,3+12,8+7]
            = [15,15,15]