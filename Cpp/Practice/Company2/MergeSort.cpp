#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int low,int mid,int high)
{
    // cout<<low<<" "<<mid<<" "<<high<<endl;
    int n1 = mid-low+1;
    int n2 = high-mid;
    int L1[n1],L2[n2];
    for(int i=0;i<n1;i++)
        L1[i]=arr[low+i];
    for(int i=0;i<n2;i++)
        L2[i]=arr[mid+1+i];
    // int temp[];
    int k=low;
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(L1[i]<=L2[j])
        {
            arr[k++]=L1[i++];
        }
        else
        {
            arr[k++]=L2[j++];
        }
    }
    while(i<n1)
    {
        arr[k++]=L1[i++];
    }
    while(j<n2)
    {
        arr[k++]=L2[j++];
    }
}
void mergeSort(int arr[],int low,int high)
{
    int mid;
    if(low>=high)
        return;
    mid = low+(high-low)/2;
    // cout<<low<<" "<<mid<<" "<<high<<endl;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}