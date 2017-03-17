//segregate zeros and ones
#include<iostream>
using namespace std;
void seg(int A[],int N)
{
    int i=0,j=1;
    while(j<=N)
    {
        if(A[i]==1&&A[j]==0)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i++;
            j++;
        }
        if(A[i]==0)
        {
            i++;
        }
        if(A[j]==1)
        {
            j++;
        }
    }
return;
}
int main()
{
    int arr[] = { 0,1,0,1,0,1,0,1,0,1};
    int N=(sizeof(arr)/sizeof(arr[0]));
    seg(arr,N-1);
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<'\n';
    }
    return 0;
}

