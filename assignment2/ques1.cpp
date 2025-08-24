#include <iostream>
using namespace std;
int binarySearch(int arr[],int n,int key)
 {
    int start=0, end=n-1;
    while(start<=end)
     {
        int mid=(start+end)/2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start=mid+1;
        else
            end=mid-1;
    }
    return -1;
}
int main()
{
int arr[10],n,key;
cout<<"enter no of elements";
cin>>n;
cout<<"enter elements";
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
cout<<"enter key";
cin>>key;
int result= binarySearch(arr, n, key);
    if (result != -1)
        cout << "element found at index " << result << endl;
    else
        cout << "element not found" << endl;
        return 0;
        }
