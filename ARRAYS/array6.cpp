//element search in sorted array
#include<iostream>
using namespace std;
int findpivot(int A[],int N)
{
    int pivot=0;
    for(int i=0;i<N;i++)
    {
        if(A[pivot]>A[i])
        {
            pivot=i;
            return i;
        }
    }
}
void binary(int A[],int s,int N,int key)
{
    int k=(s+N)/2;
    if(A[k]==key)
    {
        cout<<k+1;
        return;
    }
    else if(A[k]<key)
    {
        //cout<<"Step2";
        binary(A,k+1,N,key);
    }
    else
    {
        //cout<<"step3";
        binary(A,s,k-1,key);
    }
}
void arraysearc(int A[],int N,int key)
{
    int i=findpivot(A,N);
    if(key>A[N])
    {
        //cout<<"step1";
        binary(A,0,i-1,key);
    }
    else
    {
        //cout<<"step2";
        binary(A,i,N,key);
    }
}
int main()
{
    int arr[]={6,7,8,9,10,1,2,3,4,5};
    int N=sizeof(arr)/sizeof(arr[0]);
    cout<<N<<'\n';
    arraysearc(arr,N-1,4);
    return 0;
}
