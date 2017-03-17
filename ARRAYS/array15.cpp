#include<iostream>
using namespace std;
int max_diff(int A[],int N)
{
    int max_dff=A[1]-A[0];
    int min_ele=A[0];
    for(int i=0;i<N;i++)
    {
        if(A[i]-min_ele>max_dff)
        {
            max_dff=A[i]-min_ele;
        }
        if(A[i]<min_ele)
        {
           min_ele=A[i];
        }
    }
return max_dff;
}
int main()
{
    int arr[] = { 7,9,4,5,6,9};
    int N=(sizeof(arr)/sizeof(arr[0]));
    cout<<max_diff(arr,N-1);
    return 0;
}
