#include <bits/stdc++.h> 
using namespace std;
long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid, long long int right) 
{ 
    long long int inv_count = 0; 
  
    long long int i = left; 
    long long int j = mid;  
    long long int k = left; 
    while ((i <= mid - 1) && (j <= right)) 
    { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else
        { 
            temp[k++] = arr[j++]; 
  
            inv_count = inv_count + (mid - i); 
        } 
    } 

    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
 
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    for (i=left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 

long long int _mergeSort(long long int arr[], long long int temp[], long long int left, long long int right) 
{ 
    long long int mid, inv_count = 0; 
    if (right > left) 
    { 
        mid = (right + left)/2; 
  
        inv_count  = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid+1, right); 
  
        inv_count += merge(arr, temp, left, mid+1, right); 
    } 
  
    return inv_count; 
} 
  
long long int countSwaps(long long int arr[], long long int n) 
{ 
    long long int temp[n]; 
    return _mergeSort(arr, temp, 0, n - 1); 
} 
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int arr[n];
        for(long long int i=0;i<n;i++)
            cin>>arr[i];
        if(n==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        long long int ans = countSwaps(arr,n);
        // cout<<ans<<endl;
        if(ans>(n*(n-1)/2)-1)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}