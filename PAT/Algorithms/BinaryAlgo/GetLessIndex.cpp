#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int getMin(vector<int> arr,int left,int right)
{
    while(left <= right)
    {
        int mid = left + (right-left)/2;
        ///cout<<mid<<endl;
        if(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1])
        {
            return mid;
        }
        else if(arr[mid]>arr[mid-1])
        {
            right = mid - 1;
        }
        else if(arr[mid]>arr[mid+1])
        {
            left = mid + 1;
        }
    }
    return -1;
}
int getLessIndex(vector<int> arr)
{
    int N = arr.size();
    if(N == 0)
    {
        return -1;
    }
    if(N == 1)
    {
        return 0;
    }
    if(arr[0] < arr[1])
    {
        return 0;
    }
    if(arr[N-1] < arr[N-2])
    {
        return N-1;
    }
    int res = getMin(arr,1,N-2);
    return res;
}

int main()
{
    int arr[] = {3,2,9,2,1,4,0,10,9,0,8,3,5,6,7,1,9,2,4,0,7};
    vector<int> vec(begin(arr),end(arr));
    cout<<getLessIndex(vec)<<endl;
}
