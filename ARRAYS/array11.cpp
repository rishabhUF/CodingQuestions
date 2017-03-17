//backtraversing
#include<iostream>
using namespace std;
void indexsort(int A[],int B[],int N)
{
    for(int i=0;i<=N;i++)
    {
        int temp=i;
        for(int j=i+1;j<=N;j++)
        {
            if(A[temp]>=A[j])
            {
                temp=j;
            }
        }
        B[i]=temp;
        int temp1=A[i];
        A[i]=A[temp];
        A[temp]=temp1;
        cout<<B[i]<<' ';
    }
    return;
}
int main()
{
    int arr[] = { 1,1,3,4,1,1,1,1,1,2,2,2,3,4,1};
    int N=(sizeof(arr)/sizeof(arr[0]));
    int A[N];
    indexsort(arr,A,N-1);
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<'\n';
    }
    return 0;
}
