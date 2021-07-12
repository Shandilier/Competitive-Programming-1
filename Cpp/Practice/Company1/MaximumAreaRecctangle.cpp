#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll matrix[n][m];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
            cin>>matrix[i][j];
    }
    ll leftMax=0,rightMax=0,topMax=0,bottomMax=0;
    ll temp[n];
    memset(temp,0,sizeof(temp));
    ll maxSumArea=0;
    for(ll i=0;i<m;i++)
    {
        for(ll j=i;j<m;j++)
        {
            for(ll k=0;k<n;k++)
            {
                temp[k]+=matrix[k][j];
            }
            // kadane's algorithm
            ll gmax=INT_MIN,maxm=INT_MIN;
            for(ll k=0;k<n;k++)
            {
                if(temp[k]>maxm+temp[k])
                {
                    maxm=temp[k];
                    topMax = k;
                }
                else
                {
                    maxm=maxm+temp[k];
                }
                if(maxm>gmax)
                {
                    gmax=maxm;
                    bottomMax=k;
                }
            }
            if(gmax>maxSumArea)
            {
                leftMax=i;
                rightMax=j;
                maxSumArea=gmax;
            }
        }
        for(ll k=0;k<n;k++)
            temp[k]=0;
    }
    cout<<leftMax<<" "<<rightMax<<" "<<topMax<<" "<<bottomMax<<" "<<maxSumArea<<endl;
}