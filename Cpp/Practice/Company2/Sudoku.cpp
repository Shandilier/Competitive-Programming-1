#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[100][100];
bool isSafe(ll arr[][100],ll row,ll col,ll num,ll n)
{
    for(ll i=0;i<n;i++)
    {
        if(arr[row][i]==num)
            return false;
    }
    for(ll i=0;i<n;i++)
    {
        if(arr[i][col]==num)
            return false;
    }
    ll startX = row-row%3;
    ll startY = col-col%3;
    for(ll i=startX;i<startX+3;i++)
    {
        for(ll j=startY;j<startY+3;j++)
        {
            if(arr[i][j]==num)
                return false;
        }
    }
    return true;
}
bool findSudoku(ll arr[][100],ll n,ll row,ll col)
{
    if(row==n-1 && col ==n)
    {
        return true;
    }
    if(col==n)
    {
        row++;
        col=0;
    }
    if(arr[row][col]>0)
        return findSudoku(arr,n,row,col+1);
    for(ll i=1;i<=n;i++)
    {
        if(isSafe(arr,row,col,i,n))
        {
            arr[row][col]=i;
            if(findSudoku(arr,n,row,col+1))
                return true;
            arr[row][col]=0;
        }
    }
    return false;
}

int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cin>>arr[i][j];
    }
    if(findSudoku(arr,n,0,0))
        cout<<"Sudoku can be solved"<<endl;
    else
    {
        cout<<"Sudoku cannot be solved"<<endl;
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
