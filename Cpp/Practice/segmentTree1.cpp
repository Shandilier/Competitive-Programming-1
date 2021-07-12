#include<bits/stdc++.h>
using namespace std;
int segArray[1000001];
void segTree(int arr[],int n,int low,int high,int index)
{
    if(low==high)
    {
        segArray[index] = arr[low];
        return segArray[index];
    }
    int mid = (low+high)/2;
    segTree(arr,n,low,mid,2*index+1);
    segTree(arr,n,mid+1,high,2*index+2);
    segArray[index] = min(segArray[2*index+1],segArray[2*index+2]);
}
int findMin(int n,int low,int high,int index)
{
    if(low == )
}
int main()
{
    int n;
    cin>>n;
    int len = pow(2,n)+1;
    int arr[n];
    segTree(arr,n,0,n-1,0);
}