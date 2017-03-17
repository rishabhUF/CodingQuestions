//pair with sum x
#include<iostream>
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
void hastwocandi(int A[],int e,int sum)
{
    merges(A,0,e);
    int i=0;
    int j=e;
    while(i<j)
    {
        if(A[i]+A[j]==sum)
        {
            cout<<A[i]<<"+"<<A[j]<<endl;
            i++;
        }
        else if(A[i]+A[j]<sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}
int main() {
    int arr[]={9,8,7,6,5,43,12,13,12,4,1,5};
    hastwocandi(arr, 12,14);
    /*for(int i = 0; i <= 13; i++) {
        cout << arr[i] << " ";
    }*/

    return 0;
}
