//dutch national flag problem
#include<iostream>
using namespace std;
int threewaypartion(int A[],int N)
{
    int i=0;
    int j=0,mid=(N+1)/2;
    int n=N;
    while(j<=N)
    {
        if(A[j]<A[mid])
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=i+1;
            j=j+1;
        }
        else if(A[j]>A[mid])
        {
            int temp1=A[j];
            A[j]=A[n];
            A[n]=temp1;
            n=n-1;
            j=j+1;
        }
        else
        {
            j++;
        }
        cout<<A[j]<<'\n';
    }
    return i;
}
int otherparam(int A[],int N)
{
    int temp;
    for(int i=N;i>=0;i--)
    {
        if(A[i]>A[i-1])
        {
            return i;
        }
    }
}
void dutchnational(int A[],int h,int mid,int lo)
{
    if(lo<h)
    {
        return;
    }
    if(A[lo]>A[mid])
    {
        int temp=A[lo];
        A[lo]=A[mid];
        A[mid]=temp;
        dutchnational(A,h,mid,lo+1);
    }
    if(A[mid]>A[h])
    {
        int temp1=A[h];
        A[h]=A[mid];
        A[mid]=temp1;
        dutchnational(A,h-1,mid,lo);
    }
}
int main()
{
    int A[] = { 0,1,0,2,0,2,0,1,0,1};
    int N=(sizeof(A)/sizeof(A[0]));
    cout<<N<<'\n';
    cout<<threewaypartion(A,N-1)<<'\n';
    for(int i=0;i<=N;i++)
    {
        cout<<A[i]<<' ';
    }
}
