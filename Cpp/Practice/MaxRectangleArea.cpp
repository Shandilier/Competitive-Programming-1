#include<bits/stdc++.h>
#define ll long long int
#define ii pair<int,int>
using namespace std;
void calc(vector<vector<int> >A,int n)
{
    if(n==0)
        return;
    int m=A[0].size();
    vector<vector<ii> >v(n,vector<ii>(m,make_pair(0,0)));
    int maxm=0;
    v[0][0]={A[0][0],A[0][0]};
    for(int i=1;i<n;i++)
    {
        if(A[i][0]==0)
        {
            v[i][0]={0,0};
        } 
        else
        {
            v[i][0]={1,v[i-1][0].second+1};
            maxm=max(maxm,v[i][0].first*v[i][0].second);
        }

    }
    for(int j=1;j<m;j++)
    {
        if(A[0][j]==0)
        {
            v[0][j]={0,0};
        }
        else
        {
            v[0][j]={v[0][j-1].first+1,1};
            maxm=max(maxm,v[0][j].first*v[0][j].second);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(A[i][j]==0)
            {
                v[i][j]={0,0};
                cout<<0<<"    ";
            }
            else
            {
                v[i][j]={v[i][j-1].first+1,v[i-1][j].second+1};
                maxm=max(maxm,v[i][j].first*v[i][j].second);
                cout<<v[i][j].first*v[i][j].second<<"    ";
            }
            
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> >A(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>A[i][j];
    }
    calc(A,n);
    return 0;
}