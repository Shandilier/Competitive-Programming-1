#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int start,int end)
{
    int pivot = arr[end];
    int index = start;
    for(int i=start;i<end;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[index]);
            index++;
        }
    }
    swap(arr[end],arr[index]);
    return index;
}

void QuickSort(int arr[],int start,int end)
{
    int index;
    if(start<end)
    {
        index = partition(arr,start,end);
        QuickSort(arr,start,index-1);
        QuickSort(arr,index+1,end);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int partitionIndex;
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}