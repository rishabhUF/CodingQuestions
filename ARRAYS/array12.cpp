//closest to zero
#include<iostream>
#include<stdlib.h>
using namespace std;
void merge(int A[],int s,int e)
{
    int i=s;
    int k=0;
    int m=(s+e)/2;
    int j=m+1;
    int temp[100];
    while(i<=m&&j<=e)
    {
        if(A[i]<A[j])
        {
            temp[k]=A[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=A[j];
            k++;
            j++;
        }
    }
    while(i<=m)
    {
        temp[k]=A[i];
        k++;
        i++;
    }
    while(j<=e)
    {
        temp[k]=A[j];
        k++;
        j++;
    }
    for(int t=s;t<=e;t++)
    {
        A[t]=temp[t-s];
    }
    return;
}
void merges(int a[],int s,int e)
{
    if(s==e)
    {
        return;
    }
    int m=(s+e)/2;
    merges(a,s,m);
    merges(a,m+1,e);
    merge(a,s,e);
}
void closest(int A[],int N)
{
    int l=0,r=N,sum;
    merges(A,0,N);
    int min_sum=A[r];
    int min_l=0,min_r=N;
    while(l<r)
    {
        sum=A[l]+A[r];
        if(abs(min_sum)>abs(sum))
        {
            min_sum=sum;
            min_l=l;
            min_r=r;
        }
        l++;
        r--;
    }
    cout<<min_sum;
   return;
}
int main()
{
    int arr[] = { 1,60,-10,70,-80,85};
    int N=(sizeof(arr)/sizeof(arr[0]));
    closest(arr,N-1);
    return 0;
}
